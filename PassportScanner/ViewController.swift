//
//  ViewController.swift
//  PassportScanner
//
//  Created by Edwin Vermeer on 9/8/15.
//  Copyright (c) 2015 Mirabeau. All rights reserved.
//

import UIKit

class ViewController: UIViewController, ProcessMRZ {

    /// Just put the scan result in this label.
    @IBOutlet weak var mrzLabel: UILabel!

    /**
    Make sure we only have the app in .Portrait
    
    :returns: .Portrait orientation
    */
    override func supportedInterfaceOrientations() -> UIInterfaceOrientationMask {
        return UIInterfaceOrientationMask.Portrait
    }
    
    /**
    Hide the status bar
    
    :returns: true will hide the status bar
    */
    override func prefersStatusBarHidden() -> Bool {
        return true
    }

    /**
    This function will be executed after pressing the scan button
    
    :param: sender The sender of the event
    */
    @IBAction func StartScan(sender: AnyObject) {
        let storyboard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
        let scanVC: MyScanViewController = storyboard.instantiateViewControllerWithIdentifier("PassportScanner") as! MyScanViewController
        scanVC.delegate = self
        self.presentViewController(scanVC, animated: true, completion: nil)
    }
    
    /**
    protocol function for ProcessMRZ for receiving the scanned MRZ
    
    :param: mrz The scanned MRZ
    */
    func processMRZ(mrz:MRZ) {
        self.mrzLabel.text = mrz.description
        mrzLabel.sizeToFit()
    }
}

