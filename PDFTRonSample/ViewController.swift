//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
import UIKit
import PDFNet
import Tools
class ViewController: UIViewController {
    
    override func viewDidAppear(_ animated: Bool) {
        // Create a PTDocumentController
        PTOverrides.overrideClass(PTDocumentController.self, with: MyDocumentController.self)
        PTOverrides.overrideClass(PTToolGroupToolbar.self, with: GroupToolbar.self)
        let documentController = MyDocumentController()
        // The PTDocumentController must be in a navigation controller before a document can be opened
        let navigationController = UINavigationController(rootViewController: documentController)
        navigationController.modalPresentationStyle = .fullScreen
        navigationController.navigationBar.isTranslucent = false
        navigationController.toolbar.isTranslucent = false
        // Open a file from URL.
        let fileURL: URL = URL(string:"https://pdftron.s3.amazonaws.com/downloads/pl/sample.pdf")!
        documentController.openDocument(with: fileURL)
        // Show navigation (and document) controller.
        self.present(navigationController, animated: true, completion: nil)
    }
}
class GroupToolbar: PTToolGroupToolbar {
    override func  setPresetsViewHidden(_ hidden: Bool, animated: Bool) {
        super.setPresetsViewHidden(true, animated: animated)
    }
}
    
class MyDocumentController : PTDocumentController
{
    override func toolManager(_ toolManager: PTToolManager, annotationModified annotation: PTAnnot, onPageNumber pageNumber: UInt) {
         setToolbarColorForAnnotation(annotation)
     }
     
     func setToolbarColorForAnnotation(_ annot: PTAnnot){
         
         let drawclass = self.toolGroupManager.annotateItemGroup.barButtonItems;
         
         let tool = drawclass?.first(where: { button in
             (button as! PTToolBarButtonItem).toolClass?.annotType == annot.extendedAnnotType
         })
         let style = PTAnnotStyle(annotType: annot.extendedAnnotType)
         (tool as! PTToolBarButtonItem).setImageStyle(style)
     }
}
