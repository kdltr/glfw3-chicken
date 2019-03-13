// NOTE: This is an altered version of the original glfw.h file
// The following changes were made to work with CHICKEN bind:
// + removed __cplusplus ifdefs
// + add struct names (identical to typedefs)
// + add ___safe to glfwWaitEvents and glfwPollEvents
// + remove const from GLFWerrorfun typedef (silences warning)
// + remove version defs
// + redefine ints as bools where appropriate
// + redefine defs whose value was other defs
// + removed SYSTEM/COMPILER SPECIFIC section (silences warnings)
// + delete GLFWAPI everywhere
// + removed client API headers section (silences warnings)
// + removed _glfw3_h_ ifdefs (not really necessary)


#include <stdbool.h>


#define GLFW_RELEASE                0
#define GLFW_PRESS                  1
#define GLFW_REPEAT                 2


#define GLFW_KEY_UNKNOWN            -1

#define GLFW_KEY_SPACE              32
#define GLFW_KEY_APOSTROPHE         39  /* ' */
#define GLFW_KEY_COMMA              44  /* , */
#define GLFW_KEY_MINUS              45  /* - */
#define GLFW_KEY_PERIOD             46  /* . */
#define GLFW_KEY_SLASH              47  /* / */
#define GLFW_KEY_0                  48
#define GLFW_KEY_1                  49
#define GLFW_KEY_2                  50
#define GLFW_KEY_3                  51
#define GLFW_KEY_4                  52
#define GLFW_KEY_5                  53
#define GLFW_KEY_6                  54
#define GLFW_KEY_7                  55
#define GLFW_KEY_8                  56
#define GLFW_KEY_9                  57
#define GLFW_KEY_SEMICOLON          59  /* ; */
#define GLFW_KEY_EQUAL              61  /* = */
#define GLFW_KEY_A                  65
#define GLFW_KEY_B                  66
#define GLFW_KEY_C                  67
#define GLFW_KEY_D                  68
#define GLFW_KEY_E                  69
#define GLFW_KEY_F                  70
#define GLFW_KEY_G                  71
#define GLFW_KEY_H                  72
#define GLFW_KEY_I                  73
#define GLFW_KEY_J                  74
#define GLFW_KEY_K                  75
#define GLFW_KEY_L                  76
#define GLFW_KEY_M                  77
#define GLFW_KEY_N                  78
#define GLFW_KEY_O                  79
#define GLFW_KEY_P                  80
#define GLFW_KEY_Q                  81
#define GLFW_KEY_R                  82
#define GLFW_KEY_S                  83
#define GLFW_KEY_T                  84
#define GLFW_KEY_U                  85
#define GLFW_KEY_V                  86
#define GLFW_KEY_W                  87
#define GLFW_KEY_X                  88
#define GLFW_KEY_Y                  89
#define GLFW_KEY_Z                  90
#define GLFW_KEY_LEFT_BRACKET       91  /* [ */
#define GLFW_KEY_BACKSLASH          92  /* \ */
#define GLFW_KEY_RIGHT_BRACKET      93  /* ] */
#define GLFW_KEY_GRAVE_ACCENT       96  /* ` */
#define GLFW_KEY_WORLD_1            161 /* non-US #1 */
#define GLFW_KEY_WORLD_2            162 /* non-US #2 */

#define GLFW_KEY_ESCAPE             256
#define GLFW_KEY_ENTER              257
#define GLFW_KEY_TAB                258
#define GLFW_KEY_BACKSPACE          259
#define GLFW_KEY_INSERT             260
#define GLFW_KEY_DELETE             261
#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_DOWN               264
#define GLFW_KEY_UP                 265
#define GLFW_KEY_PAGE_UP            266
#define GLFW_KEY_PAGE_DOWN          267
#define GLFW_KEY_HOME               268
#define GLFW_KEY_END                269
#define GLFW_KEY_CAPS_LOCK          280
#define GLFW_KEY_SCROLL_LOCK        281
#define GLFW_KEY_NUM_LOCK           282
#define GLFW_KEY_PRINT_SCREEN       283
#define GLFW_KEY_PAUSE              284
#define GLFW_KEY_F1                 290
#define GLFW_KEY_F2                 291
#define GLFW_KEY_F3                 292
#define GLFW_KEY_F4                 293
#define GLFW_KEY_F5                 294
#define GLFW_KEY_F6                 295
#define GLFW_KEY_F7                 296
#define GLFW_KEY_F8                 297
#define GLFW_KEY_F9                 298
#define GLFW_KEY_F10                299
#define GLFW_KEY_F11                300
#define GLFW_KEY_F12                301
#define GLFW_KEY_F13                302
#define GLFW_KEY_F14                303
#define GLFW_KEY_F15                304
#define GLFW_KEY_F16                305
#define GLFW_KEY_F17                306
#define GLFW_KEY_F18                307
#define GLFW_KEY_F19                308
#define GLFW_KEY_F20                309
#define GLFW_KEY_F21                310
#define GLFW_KEY_F22                311
#define GLFW_KEY_F23                312
#define GLFW_KEY_F24                313
#define GLFW_KEY_F25                314
#define GLFW_KEY_KP_0               320
#define GLFW_KEY_KP_1               321
#define GLFW_KEY_KP_2               322
#define GLFW_KEY_KP_3               323
#define GLFW_KEY_KP_4               324
#define GLFW_KEY_KP_5               325
#define GLFW_KEY_KP_6               326
#define GLFW_KEY_KP_7               327
#define GLFW_KEY_KP_8               328
#define GLFW_KEY_KP_9               329
#define GLFW_KEY_KP_DECIMAL         330
#define GLFW_KEY_KP_DIVIDE          331
#define GLFW_KEY_KP_MULTIPLY        332
#define GLFW_KEY_KP_SUBTRACT        333
#define GLFW_KEY_KP_ADD             334
#define GLFW_KEY_KP_ENTER           335
#define GLFW_KEY_KP_EQUAL           336
#define GLFW_KEY_LEFT_SHIFT         340
#define GLFW_KEY_LEFT_CONTROL       341
#define GLFW_KEY_LEFT_ALT           342
#define GLFW_KEY_LEFT_SUPER         343
#define GLFW_KEY_RIGHT_SHIFT        344
#define GLFW_KEY_RIGHT_CONTROL      345
#define GLFW_KEY_RIGHT_ALT          346
#define GLFW_KEY_RIGHT_SUPER        347
#define GLFW_KEY_MENU               348
#define GLFW_KEY_LAST               348



#define GLFW_MOD_SHIFT           0x0001
#define GLFW_MOD_CONTROL         0x0002
#define GLFW_MOD_ALT             0x0004
#define GLFW_MOD_SUPER           0x0008


#define GLFW_MOUSE_BUTTON_1         0
#define GLFW_MOUSE_BUTTON_2         1
#define GLFW_MOUSE_BUTTON_3         2
#define GLFW_MOUSE_BUTTON_4         3
#define GLFW_MOUSE_BUTTON_5         4
#define GLFW_MOUSE_BUTTON_6         5
#define GLFW_MOUSE_BUTTON_7         6
#define GLFW_MOUSE_BUTTON_8         7
#define GLFW_MOUSE_BUTTON_LAST      7
#define GLFW_MOUSE_BUTTON_LEFT      0
#define GLFW_MOUSE_BUTTON_RIGHT     1
#define GLFW_MOUSE_BUTTON_MIDDLE    2

#define GLFW_JOYSTICK_1             0
#define GLFW_JOYSTICK_2             1
#define GLFW_JOYSTICK_3             2
#define GLFW_JOYSTICK_4             3
#define GLFW_JOYSTICK_5             4
#define GLFW_JOYSTICK_6             5
#define GLFW_JOYSTICK_7             6
#define GLFW_JOYSTICK_8             7
#define GLFW_JOYSTICK_9             8
#define GLFW_JOYSTICK_10            9
#define GLFW_JOYSTICK_11            10
#define GLFW_JOYSTICK_12            11
#define GLFW_JOYSTICK_13            12
#define GLFW_JOYSTICK_14            13
#define GLFW_JOYSTICK_15            14
#define GLFW_JOYSTICK_16            15
#define GLFW_JOYSTICK_LAST          15

#define GLFW_NOT_INITIALIZED        0x00010001
#define GLFW_NO_CURRENT_CONTEXT     0x00010002
#define GLFW_INVALID_ENUM           0x00010003
#define GLFW_INVALID_VALUE          0x00010004
#define GLFW_OUT_OF_MEMORY          0x00010005
#define GLFW_API_UNAVAILABLE        0x00010006
#define GLFW_VERSION_UNAVAILABLE    0x00010007
#define GLFW_PLATFORM_ERROR         0x00010008
#define GLFW_FORMAT_UNAVAILABLE     0x00010009
#define GLFW_NO_WINDOW_CONTEXT      0x0001000A

#define GLFW_FOCUSED                0x00020001
#define GLFW_ICONIFIED              0x00020002
#define GLFW_RESIZABLE              0x00020003
#define GLFW_VISIBLE                0x00020004
#define GLFW_DECORATED              0x00020005
#define GLFW_AUTO_ICONIFY           0x00020006
#define GLFW_FLOATING               0x00020007
#define GLFW_MAXIMIZED              0x00020008

#define GLFW_RED_BITS               0x00021001
#define GLFW_GREEN_BITS             0x00021002
#define GLFW_BLUE_BITS              0x00021003
#define GLFW_ALPHA_BITS             0x00021004
#define GLFW_DEPTH_BITS             0x00021005
#define GLFW_STENCIL_BITS           0x00021006
#define GLFW_ACCUM_RED_BITS         0x00021007
#define GLFW_ACCUM_GREEN_BITS       0x00021008
#define GLFW_ACCUM_BLUE_BITS        0x00021009
#define GLFW_ACCUM_ALPHA_BITS       0x0002100A
#define GLFW_AUX_BUFFERS            0x0002100B
#define GLFW_STEREO                 0x0002100C
#define GLFW_SAMPLES                0x0002100D
#define GLFW_SRGB_CAPABLE           0x0002100E
#define GLFW_REFRESH_RATE           0x0002100F
#define GLFW_DOUBLEBUFFER           0x00021010

#define GLFW_CLIENT_API             0x00022001
#define GLFW_CONTEXT_VERSION_MAJOR  0x00022002
#define GLFW_CONTEXT_VERSION_MINOR  0x00022003
#define GLFW_CONTEXT_REVISION       0x00022004
#define GLFW_CONTEXT_ROBUSTNESS     0x00022005
#define GLFW_OPENGL_FORWARD_COMPAT  0x00022006
#define GLFW_OPENGL_DEBUG_CONTEXT   0x00022007
#define GLFW_OPENGL_PROFILE         0x00022008
#define GLFW_CONTEXT_RELEASE_BEHAVIOR 0x00022009
#define GLFW_CONTEXT_NO_ERROR       0x0002200A
#define GLFW_CONTEXT_CREATION_API   0x0002200B

#define GLFW_NO_API                          0
#define GLFW_OPENGL_API             0x00030001
#define GLFW_OPENGL_ES_API          0x00030002

#define GLFW_NO_ROBUSTNESS                   0
#define GLFW_NO_RESET_NOTIFICATION  0x00031001
#define GLFW_LOSE_CONTEXT_ON_RESET  0x00031002

#define GLFW_OPENGL_ANY_PROFILE              0
#define GLFW_OPENGL_CORE_PROFILE    0x00032001
#define GLFW_OPENGL_COMPAT_PROFILE  0x00032002

#define GLFW_CURSOR                 0x00033001
#define GLFW_STICKY_KEYS            0x00033002
#define GLFW_STICKY_MOUSE_BUTTONS   0x00033003

#define GLFW_CURSOR_NORMAL          0x00034001
#define GLFW_CURSOR_HIDDEN          0x00034002
#define GLFW_CURSOR_DISABLED        0x00034003

#define GLFW_ANY_RELEASE_BEHAVIOR            0
#define GLFW_RELEASE_BEHAVIOR_FLUSH 0x00035001
#define GLFW_RELEASE_BEHAVIOR_NONE  0x00035002

#define GLFW_NATIVE_CONTEXT_API     0x00036001
#define GLFW_EGL_CONTEXT_API        0x00036002


#define GLFW_ARROW_CURSOR           0x00036001
#define GLFW_IBEAM_CURSOR           0x00036002
#define GLFW_CROSSHAIR_CURSOR       0x00036003
#define GLFW_HAND_CURSOR            0x00036004
#define GLFW_HRESIZE_CURSOR         0x00036005
#define GLFW_VRESIZE_CURSOR         0x00036006

#define GLFW_CONNECTED              0x00040001
#define GLFW_DISCONNECTED           0x00040002

#define GLFW_DONT_CARE              -1


typedef void (*GLFWglproc)(void);

typedef void (*GLFWvkproc)(void);

typedef struct GLFWmonitor GLFWmonitor;

typedef struct GLFWwindow GLFWwindow;

typedef struct GLFWcursor GLFWcursor;

typedef void (* GLFWerrorfun)(int, char*);

typedef void (* GLFWwindowposfun)(GLFWwindow*,int,int);

typedef void (* GLFWwindowsizefun)(GLFWwindow*,int,int);

typedef void (* GLFWwindowclosefun)(GLFWwindow*);

typedef void (* GLFWwindowrefreshfun)(GLFWwindow*);

typedef void (* GLFWwindowfocusfun)(GLFWwindow*,int);

typedef void (* GLFWwindowiconifyfun)(GLFWwindow*,int);

typedef void (* GLFWframebuffersizefun)(GLFWwindow*,int,int);

typedef void (* GLFWmousebuttonfun)(GLFWwindow*,int,int,int);

typedef void (* GLFWcursorposfun)(GLFWwindow*,double,double);

typedef void (* GLFWcursorenterfun)(GLFWwindow*,int);

typedef void (* GLFWscrollfun)(GLFWwindow*,double,double);

typedef void (* GLFWkeyfun)(GLFWwindow*,int,int,int,int);

typedef void (* GLFWcharfun)(GLFWwindow*,unsigned int);

typedef void (* GLFWcharmodsfun)(GLFWwindow*,unsigned int,int);

typedef void (* GLFWdropfun)(GLFWwindow*,int,const char**);

typedef void (* GLFWmonitorfun)(GLFWmonitor*,int);

typedef void (* GLFWjoystickfun)(int,int);


typedef struct GLFWvidmode
{
    /*! The width, in screen coordinates, of the video mode.
     */
    int width;
    /*! The height, in screen coordinates, of the video mode.
     */
    int height;
    /*! The bit depth of the red channel of the video mode.
     */
    int redBits;
    /*! The bit depth of the green channel of the video mode.
     */
    int greenBits;
    /*! The bit depth of the blue channel of the video mode.
     */
    int blueBits;
    /*! The refresh rate, in Hz, of the video mode.
     */
    int refreshRate;
} GLFWvidmode;

typedef struct GLFWgammaramp
{
    /*! An array of value describing the response of the red channel.
     */
    unsigned short* red;
    /*! An array of value describing the response of the green channel.
     */
    unsigned short* green;
    /*! An array of value describing the response of the blue channel.
     */
    unsigned short* blue;
    /*! The number of elements in each array.
     */
    unsigned int size;
} GLFWgammaramp;

typedef struct GLFWimage
{
    /*! The width, in pixels, of this image.
     */
    int width;
    /*! The height, in pixels, of this image.
     */
    int height;
    /*! The pixel data of this image, arranged left-to-right, top-to-bottom.
     */
    unsigned char* pixels;
} GLFWimage;



bool glfwInit(void);

void glfwTerminate(void);

void glfwGetVersion(___out int* major, ___out int* minor, ___out int* rev);

const char* glfwGetVersionString(void);

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun cbfun);

GLFWmonitor** glfwGetMonitors(___out int* count);

GLFWmonitor* glfwGetPrimaryMonitor(void);

void glfwGetMonitorPos(GLFWmonitor* monitor, ___out int* xpos, ___out int* ypos);

void glfwGetMonitorPhysicalSize(GLFWmonitor* monitor, ___out int* widthMM, ___out int* heightMM);

const char* glfwGetMonitorName(GLFWmonitor* monitor);

GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun cbfun);

const GLFWvidmode* glfwGetVideoModes(GLFWmonitor* monitor, ___out int* count);

const GLFWvidmode* glfwGetVideoMode(GLFWmonitor* monitor);

void glfwSetGamma(GLFWmonitor* monitor, float gamma);

const GLFWgammaramp* glfwGetGammaRamp(GLFWmonitor* monitor);

void glfwSetGammaRamp(GLFWmonitor* monitor, const GLFWgammaramp* ramp);

void glfwDefaultWindowHints(void);

void glfwWindowHint(int hint, int value);

___safe GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);

void glfwDestroyWindow(GLFWwindow* window);

bool glfwWindowShouldClose(GLFWwindow* window);

void glfwSetWindowShouldClose(GLFWwindow* window, bool value);

void glfwSetWindowTitle(GLFWwindow* window, const char* title);

void glfwSetWindowIcon(GLFWwindow* window, int count, const GLFWimage* images);

void glfwGetWindowPos(GLFWwindow* window, ___out int* xpos, ___out int* ypos);

void glfwSetWindowPos(GLFWwindow* window, int xpos, int ypos);

void glfwGetWindowSize(GLFWwindow* window, ___out int* width, ___out int* height);

void glfwSetWindowSizeLimits(GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight);

void glfwSetWindowAspectRatio(GLFWwindow* window, int numer, int denom);

void glfwSetWindowSize(GLFWwindow* window, int width, int height);

void glfwGetFramebufferSize(GLFWwindow* window, ___out int* width, ___out int* height);

void glfwGetWindowFrameSize(GLFWwindow* window, ___out int* left, ___out int* top, ___out int* right, ___out int* bottom);

void glfwIconifyWindow(GLFWwindow* window);

void glfwRestoreWindow(GLFWwindow* window);

void glfwMaximizeWindow(GLFWwindow* window);

void glfwShowWindow(GLFWwindow* window);

void glfwHideWindow(GLFWwindow* window);

void glfwFocusWindow(GLFWwindow* window);

GLFWmonitor* glfwGetWindowMonitor(GLFWwindow* window);

void glfwSetWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate);

int glfwGetWindowAttrib(GLFWwindow* window, int attrib);

void glfwSetWindowUserPointer(GLFWwindow* window, void* pointer);

void* glfwGetWindowUserPointer(GLFWwindow* window);

GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow* window, GLFWwindowposfun cbfun);

GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow* window, GLFWwindowsizefun cbfun);

GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow* window, GLFWwindowclosefun cbfun);

GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow* window, GLFWwindowrefreshfun cbfun);

GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow* window, GLFWwindowfocusfun cbfun);

GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow* window, GLFWwindowiconifyfun cbfun);

GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun cbfun);

___safe void glfwPollEvents(void);

___safe void glfwWaitEvents(void);

___safe void glfwWaitEventsTimeout(double timeout);

void glfwPostEmptyEvent(void);

int glfwGetInputMode(GLFWwindow* window, int mode);

void glfwSetInputMode(GLFWwindow* window, int mode, int value);

const char* glfwGetKeyName(int key, int scancode);

int glfwGetKey(GLFWwindow* window, int key);

int glfwGetMouseButton(GLFWwindow* window, int button);

void glfwGetCursorPos(GLFWwindow* window, ___out double* xpos, ___out double* ypos);

void glfwSetCursorPos(GLFWwindow* window, double xpos, double ypos);

GLFWcursor* glfwCreateCursor(const GLFWimage* image, int xhot, int yhot);

GLFWcursor* glfwCreateStandardCursor(int shape);

void glfwDestroyCursor(GLFWcursor* cursor);

void glfwSetCursor(GLFWwindow* window, GLFWcursor* cursor);

GLFWkeyfun glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun cbfun);

GLFWcharfun glfwSetCharCallback(GLFWwindow* window, GLFWcharfun cbfun);

GLFWcharmodsfun glfwSetCharModsCallback(GLFWwindow* window, GLFWcharmodsfun cbfun);

GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow* window, GLFWmousebuttonfun cbfun);

GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow* window, GLFWcursorposfun cbfun);

GLFWcursorenterfun glfwSetCursorEnterCallback(GLFWwindow* window, GLFWcursorenterfun cbfun);

GLFWscrollfun glfwSetScrollCallback(GLFWwindow* window, GLFWscrollfun cbfun);

GLFWdropfun glfwSetDropCallback(GLFWwindow* window, GLFWdropfun cbfun);

bool glfwJoystickPresent(int joy);

const float* glfwGetJoystickAxes(int joy, ___out int* count);

const unsigned char* glfwGetJoystickButtons(int joy, ___out int* count);

const char* glfwGetJoystickName(int joy);

GLFWjoystickfun glfwSetJoystickCallback(GLFWjoystickfun cbfun);

void glfwSetClipboardString(GLFWwindow* window, const char* string);

const char* glfwGetClipboardString(GLFWwindow* window);

double glfwGetTime(void);

void glfwSetTime(double time);

uint64_t glfwGetTimerValue(void);

uint64_t glfwGetTimerFrequency(void);

void glfwMakeContextCurrent(GLFWwindow* window);

GLFWwindow* glfwGetCurrentContext(void);

void glfwSwapBuffers(GLFWwindow* window);

void glfwSwapInterval(int interval);

bool glfwExtensionSupported(const char* extension);

GLFWglproc glfwGetProcAddress(const char* procname);

bool glfwVulkanSupported(void);
