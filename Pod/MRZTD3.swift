//
//  MRZ.swift
//  PassportScanner
//
//  Created by Edwin Vermeer on 12/5/14.
//  Copyright (c) 2015. All rights reserved.
//

import Foundation

@objc(MRZTD3)
open class MRZTD3: MRZParser {
    // check data with http://en.wikipedia.org/wiki/Machine-readable_passport
    
    /// Was the last scan valid. A value of 1 is for when all validations are OK
    private var _isValid: Float = 0
    
    /// Do you want to see debug messages? Set to true (see init) to see what's going on.
    private var _debug = false
    
    /// The document type from the 1st line of the MRZ. (start 1, len 1)
    @objc public var documentType: String = ""
    /// The document sub type from the 1st line of the MRZ. (start 2, len 1)
    @objc public var documentSubType: String = ""
    /// The country code from the 1st line of the MRZ (start 3, len 3)
    @objc public var countryCode: String = ""
    /// The last name from the 1st line of the MRZ (start 6, len 39, until first <<)
    @objc public var lastName: String = ""
    /// The firstname from the 1st line of the MRZ (start 6, len 39, after first <<)
    @objc public var firstName: String = ""
    
    /// The passport number from the 2nd line of the MRZ. (start 1, len 9)
    @objc public var passportNumber: String = ""
    /// start 10, len 1 - validating the passportNumber
    private var passportNumberIsValid = false
    /// The nationality from the 2nd line of the MRZ. (start 11, len 3)
    @objc public var nationality: String = ""
    /// The date of birth from the 2nd line of the MRZ (start 14, len 6)
    @objc public var dateOfBirth: Date?
    /// start 20, len 1 - validating the dateOfBirth
    private var dateOfBirthIsValid = false
    /// The sex from the 2nd line of the MRZ. (start 21, len 1)
    @objc public var sex: String = ""
    /// The expiration date from the 2nd line of the MRZ. (start 22, len 6)
    @objc public var expirationDate: Date?
    /// start 28, len 1 - validating the expirationDate
    private var expirationDateIsValid = false
    /// The personal number from the 2nd line of the MRZ. (start 29, len 14
    @objc public var personalNumber: String = ""
    /// start 43, len 1 - validating the personalNumber
    private var personalNumberIsValid = false
    // start 44, len 1 - validating passport number, date of birth, expiration date
    private var dataIsValid = false
    
    
    /**
     Convenience method for getting all data in a dictionary
     
     :returns: Return all fields in a dictionary
     */
    @objc public override func data() -> Dictionary<String, Any> {
        return ["documentType"    : documentType,
                "documentSubType" : documentSubType,
                "countryCode"     : countryCode,
                "lastName"        : lastName,
                "firstName"       : firstName,
                "passportNumber"  : passportNumber,
                "nationality"     : nationality,
                "dateOfBirth"     : MRZTD3.stringFromDate(dateOfBirth),
                "sex"             : sex,
                "expirationDate"  : MRZTD3.stringFromDate(expirationDate),
                "personalNumber"  : personalNumber]
    }
    
    /**
     Get the description of the MRZ
     
     :returns: a string with all fields plus field name (each field on a new line)
     */
    @objc open override var description: String {
        get {
            return self.data().map {"\($0) = \($1)"}.reduce("") {"\($0)\n\($1)"}
        }
    }
    
    /**
     Initiate the MRZ object with the scanned data.
     
     :param: scan  the scanned string
     :param: debug true if you want to see debug messages.
     
     :returns: Instance of MRZ
     */
    @objc public override init(scan: String, debug: Bool = false) {
        super.init(scan: scan, debug: debug)
        _debug = debug
        let lines: [String] = scan.split(separator: "\n").map({String($0)})
        var longLines: [String] = []
        for line in lines {
            let cleaned = line.replace(target: " ", with: "")
            if cleaned.count > 43 {
                longLines.append(line)
            }
        }
        if longLines.count < 2 { return }
        if longLines.count == 2 {
            process(l1: longLines[0].replace(target: " ", with: ""),
                    l2: longLines[1].replace(target: " ", with: ""))
        } else if longLines.last?.components(separatedBy: "<").count ?? 0 > 1 {
            process(l1: longLines[longLines.count-2],
                    l2: longLines[longLines.count-1])
        } else {
            process(l1: longLines[longLines.count-3].replace(target: " ", with: ""),
                    l2: longLines[longLines.count-2].replace(target: " ", with: ""))
        }
    }
    
    /**
     Do you want to see the progress in the log
     
     :param: line The data that will be logged
     */
    fileprivate func debugLog(_ line: String) {
        if _debug {
            print(line)
        }
    }
    
    @objc override func isValid() -> Float {return _isValid}
    
    
    /**
     Process the 2 MRZ lines
     
     :param: l1 First line
     :param: l2 Second line
     */
    fileprivate func process(l1: String, l2: String) {
        
        let line1 = MRZTD3.cleanup(line: l1)
        let line2 = MRZTD3.cleanup(line: l2)
        
        debugLog("Processing line 1 : \(line1)")
        debugLog("Processing line 2 : \(line2)")
        
        // Line 1 parsing
        documentType = line1.subString(0, to: 0)
        debugLog("Document type : \(documentType)")
        documentSubType = line1.subString(1, to: 1)
        countryCode = line1.subString(2, to: 4).replace(target: "<", with: " ")
        debugLog("Country code : \(countryCode)")
        let name = line1.subString(5, to: 43).replace(target: "0", with: "O")
        let nameArray = name.components(separatedBy: "<<")
        lastName = nameArray[0].replace(target: "<", with: " ")
        debugLog("Last name : \(lastName)")
        firstName = nameArray.count > 1 ? nameArray[1].replace(target: "<", with: " ") : ""
        debugLog("First name : \(firstName)")
        
        // Line 2 parsing
        passportNumber = line2.subString(0, to: 1) + line2.subString(2, to: 8).toNumber()
        debugLog("passportNumber : \(passportNumber)")
        let passportNumberCheck = line2.subString(9, to: 9).toNumber()
        nationality = line2.subString(10, to: 12).replace(target: "<", with: " ")
        debugLog("nationality : \(nationality)")
        let birth = line2.subString(13, to: 18).toNumber()
        let birthValidation = line2.subString(19, to: 19).toNumber()
        dateOfBirth = MRZTD3.dateFromString(birth, inThePast: true)
        debugLog("date of birth : \(dateOfBirth.debugDescription)")
        sex = line2.subString(20, to: 20)
        debugLog("sex : \(sex)")
        let expiration = line2.subString(21, to: 26).toNumber()
        expirationDate = MRZTD3.dateFromString(expiration)
        debugLog("date of expiration : \(expirationDate)")
        let expirationValidation = line2.subString(27, to: 27).toNumber()
        personalNumber =  line2.subString(28, to: 41).toNumber()
        debugLog("personal number : \(personalNumber)")
        let personalNumberValidation = line2.subString(42, to: 42).toNumber()
        let data = "\(passportNumber)\(passportNumberCheck)\(birth)\(birthValidation)\(expiration)\(expirationValidation)\(personalNumber)\(personalNumberValidation)"
        let dataValidation = line2.subString(43, to: 43).toNumber()
        
        // Validation
        _isValid = 1
        passportNumberIsValid = MRZTD3.validate(passportNumber, check: passportNumberCheck)
        if !passportNumberIsValid {
            print("--> PassportNumber is invalid")
        }
        _isValid = _isValid * (passportNumberIsValid ? 1 : 0.9)
        dateOfBirthIsValid = MRZTD3.validate(birth, check: birthValidation)
        if !dateOfBirthIsValid {
            print("--> DateOfBirth is invalid")
        }
        _isValid = _isValid * (dateOfBirthIsValid ? 1 : 0.9)
        _isValid = _isValid * (MRZTD3.validate(expiration, check: expirationValidation) ? 1 : 0.9)
        personalNumberIsValid = MRZTD3.validate(personalNumber, check: personalNumberValidation)
        if !personalNumberIsValid {
            print("--> PersonalNumber is invalid")
        }
        _isValid = _isValid * (personalNumberIsValid ? 1 : 0.9)
        dataIsValid = MRZTD3.validate(data, check: dataValidation)
        if !dataIsValid {
            print("--> Date is invalid")
        }
        _isValid = _isValid * (dataIsValid ? 1 : 0.9)
        
        // Final cleaning up
        documentSubType = documentSubType.replace(target: "<", with: "")
        personalNumber = personalNumber.replace(target: "<", with: "")
    }
    
    /**
     Cleanup a line of text
     
     :param: line The line that needs to be cleaned up
     :returns: Returns the cleaned up text
     */
    fileprivate class func cleanup(line: String) -> String {
        let t = line.components(separatedBy: " ")
        if t.count > 1 {
            // are there extra characters added
            for p in t {
                if p.count == 44 {
                    return p
                }
            }
            // was there one or more extra space added
            if "\(t[0])\(t[1])".count == 44 {
                return "\(t[0])\(t[1])"
            } else if  "\(t[t.count-2])\(t[t.count-1])".count == 44 {
                return "\(t[t.count-2])\(t[t.count-1])"
            } else {
                return line.replace(target: " ", with: "")
            }
        }
        return line // assume the garbage characters are at the end
    }
    
}

