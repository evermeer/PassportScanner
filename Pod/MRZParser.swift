//
//  MRZParser.swift
//  PassportScanner
//
//  Created by Valerio Ferrantelli on 15/10/18.
//  Copyright © 2018 evict. All rights reserved.
//

import Foundation

@objc(MRZParser)
open class MRZParser : NSObject{
    
    @objc public var parsedMRZ: String = ""

    
    @objc public init(scan: String, debug: Bool = false) {
        super.init()
        parsedMRZ = scan
    }
    
    /// Was the last scan valid. A value of 1 is for when all validations are OK
    @objc func isValid() -> Float {return 0}
    
    // A dictionary with mrz parsed fields
    @objc public func data() -> Dictionary<String, Any> {return Dictionary.init()}

    
    
    /**
     Create a date from a string
     
     :param: value The string value that needs to be converted to a date
     
     :returns: Returns the date value for the string and force it to be in the past
     */
    class func dateFromString(_ value: String, inThePast: Bool = false) -> Date? {
        var date: Date?
        let dateStringFormatter = DateFormatter()
        dateStringFormatter.dateFormat = "YYMMdd"
        dateStringFormatter.locale = Locale(identifier: "en_US_POSIX")
        dateStringFormatter.timeZone = TimeZone(abbreviation: "GMT+0:00")
        let d = dateStringFormatter.date(from: value)
        if d != nil {
            date = Date(timeInterval: 0, since: d!)
        }
        if let dateU = date, dateU > Date(), inThePast {
            date = Calendar.current.date(byAdding: .year, value: -100, to: dateU)
        }
        return date
    }
    
    /**
     Create a string from a date
     
     :param: value The Date value that needs to be converted to a string
     
     :returns: Returns the string value for the date
     */
    class func stringFromDate(_ value: Date?) -> String {
        if value == nil {
            return ""
        }
        let formatter = DateFormatter()
        formatter.dateFormat = "YYMMdd"
        formatter.locale = Locale(identifier: "en_US_POSIX")
        return formatter.string(from: value!)
    }
    
    /**
     MRZ data validation function
     
     :param: data The data that needs to be validated
     :param: check The checksum string for the validation
     
     :returns: Returns true if the data was valid
     */
    class func validate(_ data: String, check: String) -> Bool {
        // The check digit calculation is as follows: each position is assigned a value; for the digits 0 to 9 this is
        // the value of the digits, for the letters A to Z this is 10 to 35, for the filler < this is 0. The value of
        // each position is then multiplied by its weight; the weight of the first position is 7, of the second it is 3,
        // and of the third it is 1, and after that the weights repeat 7, 3, 1, etcetera. All values are added together
        // and the remainder of the final value divided by 10 is the check digit.
        
        print("Check '\(data)' for check '\(check)'")
        var i: Int = 1
        var dc: Int = 0
        var w: [Int] = [7,3,1]
        let b0: UInt8 = "0".utf8.first!
        let b9: UInt8 = "9".utf8.first!
        let bA: UInt8 = "A".utf8.first!
        let bZ: UInt8 = "Z".utf8.first!
        let bK: UInt8 = "<".utf8.first!
        for c: UInt8 in Array(data.utf8) {
            var d: Int = 0
            if c >= b0 && c <= b9 {
                d = Int(c - b0)
            } else if c >= bA && c <= bZ {
                d = Int((10 + c) - bA)
            } else if c != bK {
                return false
            }
            dc = dc + d * w[(i-1)%3]
            //print("i = \(i)   c = \(c)   d = \(d)   w = \(w[(i-1)%3])   dc = \(dc)")
            i += 1
        }
        if dc%10 != Int(check) {
            return false
        }
        //NSLog("Item was valid")
        return true
    }
}


extension String {
    
    /**
     Simple string extension for performing a replace
     
     :param: target     search this text
     :param: withString the text you want to replace it with
     
     :returns: the string with the replacements.
     */
    func replace(target: String, with: String) -> String {
        return self.replacingOccurrences(of: target, with: with, options: .literal, range: nil)
    }
    
    /**
     Clean up incorrect detected characters
     
     :returns: The cleaned up string
     */
    func toNumber() -> String {
        return self
            .replace(target: "O", with: "0")
            .replace(target: "Q", with: "0")
            .replace(target: "U", with: "0")
            .replace(target: "D", with: "0")
            .replace(target: "I", with: "1")
            .replace(target: "Z", with: "2")
    }
    
    /**
     Get a substring
     
     :param: from from which character
     :param: to   to what character
     
     :returns: Return the substring
     */
    func subString(_ from: Int, to: Int) -> String {
        let f: String.Index = self.index(self.startIndex, offsetBy: from)
        let t: String.Index = self.index(self.startIndex, offsetBy: to + 1)
        return self.substring(with: f..<t)
    }
}


