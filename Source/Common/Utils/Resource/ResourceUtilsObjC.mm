//
//  ResourceUtilsObjC.m
//  GameDevFramework
//
//  Created by Bradley Flood on 12-08-30.
//  Copyright (c) 2012 Algonquin College. All rights reserved.
//

#import "ResourceUtilsObjC.h"


namespace ResourceUtilsObjC 
{
  void getResourcePath(std::string& aReturnPath)
  {
    @autoreleasepool
    {
      aReturnPath = std::string([[[NSBundle mainBundle] resourcePath] UTF8String]);
    }
  }
}

