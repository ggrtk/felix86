// Read abi.cpp -> signature format
// X(lib name, func name, signature)
X("libGLX.so", glXChooseVisual, q_qdq)
X("libGLX.so", glXCreateContext, q_qqqd)
X("libGLX.so", glXDestroyContext, v_qq)
X("libGLX.so", glXMakeCurrent, d_qqq)
X("libGLX.so", glXCopyContext, v_qqqq)
X("libGLX.so", glXSwapBuffers, v_qq)
X("libGLX.so", glXCreateGLXPixmap, q_qqq)
X("libGLX.so", glXDestroyGLXPixmap, v_qq)
X("libGLX.so", glXQueryExtension, d_qqq)
X("libGLX.so", glXQueryVersion, d_qqq)
X("libGLX.so", glXIsDirect, d_qq)
X("libGLX.so", glXGetConfig, d_qqdq)
X("libGLX.so", glXGetCurrentContext, q_)
X("libGLX.so", glXGetCurrentDrawable, q_)
X("libGLX.so", glXWaitGL, v_)
X("libGLX.so", glXWaitX, v_)
X("libGLX.so", glXUseXFont, v_qddd)
X("libGLX.so", glXChooseFBConfig, q_qdqq)
X("libGLX.so", glXCreateNewContext, q_qqdqd)
X("libGLX.so", glXCreatePbuffer, q_qqq)
X("libGLX.so", glXCreatePixmap, q_qqqq)
X("libGLX.so", glXCreateWindow, q_qqqq)
X("libGLX.so", glXDestroyPbuffer, v_qq)
X("libGLX.so", glXDestroyPixmap, v_qq)
X("libGLX.so", glXDestroyWindow, v_qq)
X("libGLX.so", glXGetClientString, q_qd)
X("libGLX.so", glXGetCurrentDisplay, q_)
X("libGLX.so", glXGetCurrentReadDrawable, q_)
X("libGLX.so", glXGetFBConfigAttrib, d_qqdq)
X("libGLX.so", glXGetFBConfigs, q_qdq)
X("libGLX.so", glXGetProcAddress, q_q)
X("libGLX.so", glXGetProcAddressARB, q_q)
X("libGLX.so", glXGetSelectedEvent, v_qqq)
X("libGLX.so", glXGetVisualFromFBConfig, q_qq)
X("libGLX.so", glXMakeContextCurrent, d_qqqq)
X("libGLX.so", glXQueryContext, d_qqdq)
X("libGLX.so", glXQueryDrawable, d_qqdq)
X("libGLX.so", glXQueryExtensionsString, q_qd)
X("libGLX.so", glXQueryServerString, q_qdd)
X("libGLX.so", glXSelectEvent, v_qqq)
X("libGLX.so", __glXGLLoadGLXFunction, q_qqq)

// GLX_MESA_query_renderer
X("libGLX.so", glXQueryRendererIntegerMESA, d_qdddq)
X("libGLX.so", glXQueryCurrentRendererIntegerMESA, d_dq)
X("libGLX.so", glXQueryRendererStringMESA, q_qddd)
X("libGLX.so", glXQueryCurrentRendererStringMESA, q_d)

// GLX_ARB_create_context
X("libGLX.so", glXCreateContextAttribsARB, q_qqqdq)

// EXT_swap_control
X("libGLX.so", glXSwapIntervalEXT, v_qqd)

// GLX_MESA_swap_control
X("libGLX.so", glXSwapIntervalMESA, d_d)
X("libGLX.so", glXGetSwapIntervalMESA, d_)

// GLX_SGI_swap_control
X("libGLX.so", glXSwapIntervalSGI, d_d)
