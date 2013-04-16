//
//  ResourceUtils.cpp
//  GameDevFramework
//
//  Created by Bradley Flood on 12-08-30.
//  Copyright (c) 2012 Algonquin College. All rights reserved.
//

#include "ResourceUtils.h"

#include <stdlib.h>

#ifdef __APPLE__
  #include "TargetConditionals.h"
  #if TARGET_OS_IPHONE || TARGET_OS_MAC
    #include "ResourceUtilsObjC.h"
  #endif
#endif


std::string ResourceUtils::getPathForResource(const char* aFileName, const char* aFileType)
{
#if TARGET_OS_IPHONE || TARGET_OS_MAC
  std::string path;
  ResourceUtilsObjC::getResourcePath(path);
  path.append("/");
#else
	std::string path = "../../../Resources/";
#endif
	path.append(aFileName);
	path.append(".");
	path.append(aFileType);
	return path;

}