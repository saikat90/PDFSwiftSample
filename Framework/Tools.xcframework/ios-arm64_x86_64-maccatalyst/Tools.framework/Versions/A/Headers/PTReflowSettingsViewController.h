//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTReflowCommon.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTReflowSettingsViewController;

/**
 * The methods declared by the `PTReflowSettingsViewControllerDelegate` protocol allow the adopting class
 * to respond to messages from the `PTReflowSettingsViewController` class.
 */
PT_OBJC_RUNTIME_NAME(ReflowSettingsViewControllerDelegate)
@protocol PTReflowSettingsViewControllerDelegate <NSObject>
@optional

/**
 * Notifies the delegate that the `PTReflowSettingsViewController` updated its settings.
 */
-(void)reflowSettingsViewControllerDidUpdateImageOptions:(PTReflowSettingsViewController *)reflowSettingsViewController;

/**
 * Notifies the delegate that the `PTReflowSettingsViewController` updated its scrolling direction setting.
 */
-(void)reflowSettingsViewController:(PTReflowSettingsViewController *)reflowSettingsViewController didUpdateScrollingDirection:(PTReflowViewControllerScrollingDirection)scrollingDirection;

/**
 * Notifies the delegate that the `PTReflowSettingsViewController` updated its annotation mode settings.
 */
 -(void)reflowSettingsViewController:(PTReflowSettingsViewController *)reflowSettingsViewController didSetAnnotationModeEnabled:(BOOL)enabled;

@end

PT_EXPORT
/**
 * The `PTReflowSettingsViewController` class displays settings to control the 'PTReflow'.
 */
PT_OBJC_RUNTIME_NAME(PTReflowSettingsViewController)
@interface PTReflowSettingsViewController : UITableViewController

/**
 * The PTReflowSettingsViewController's delegate.
 */
@property (nonatomic, weak, nullable) id<PTReflowSettingsViewControllerDelegate> delegate;

/**
 * `true` if background images should be hidden; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL hideBackgroundImages;

/**
 * `true` if images should be hidden under text; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL hideImagesUnderText;

/**
 * `true` if images should be hidden under invisible text; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL hideImagesUnderInvisibleText;

/**
 * `true` if text should not reflow over images; `false` otherwise. Default is `false`.
 */
@property (nonatomic, assign) BOOL doNotReflowTextOverImages;

/**
 * The scrolling direction of a reflow view controller. Default is `PTReflowViewControllerScrollingDirectionAutomatic`.
 */
@property (nonatomic, assign) PTReflowViewControllerScrollingDirection scrollingDirection;

/**
 * `true` if can create annotation; `false` otherwise. Default is `true`.
 * This property will be ignored if `annotationToolsHidden` is `true`.
 */
 @property (nonatomic, assign) BOOL annotationModeEnabled;

 /**
  * `true` if can toggle annotation mode; `false` otherwise. Default is `false`.
  */
 @property (nonatomic, assign) BOOL annotationToolsHidden;

@end

NS_ASSUME_NONNULL_END
