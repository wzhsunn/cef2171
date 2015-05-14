// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/task_cpptoc.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK task_execute(struct _cef_task_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTaskCppToC::Get(self)->Execute();
}


// CONSTRUCTOR - Do not edit by hand.

CefTaskCppToC::CefTaskCppToC(CefTask* cls)
    : CefCppToC<CefTaskCppToC, CefTask, cef_task_t>(cls) {
  struct_.struct_.execute = task_execute;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefTaskCppToC, CefTask,
    cef_task_t>::DebugObjCt = 0;
#endif

