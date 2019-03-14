(module glfw3 (make-window
               with-window
               window
               make-context-current
               init
               window-position-callback
               window-size-callback
               window-close-callback
               window-focus-callback
               window-iconify-callback
               framebuffer-size-callback
               mouse-button-callback
               cursor-enter-callback
               cursor-position-callback
               scroll-callback
               key-callback
               char-callback
               char-mods-callback
               monitor-callback
               joystick-callback
               set-window-position-callback!
               set-window-size-callback!
               set-window-close-callback!
               set-window-focus-callback!
               set-window-iconify-callback!
               set-framebuffer-size-callback!
               set-mouse-button-callback!
               set-cursor-enter-callback!
               set-cursor-position-callback!
               set-scroll-callback!
               set-key-callback!
               set-char-callback!
               set-char-mods-callback!
               set-monitor-callback!
               set-joystick-callback!
               get-monitor-position
               get-window-position
               get-cursor-position
               set-window-position
               set-cursor-position
               window-should-close?
               )

(import scheme
        (chicken base)
        (chicken foreign)
        (chicken module)
        (chicken keyword)
        (prefix glfw3-bindings %))

(reexport (except glfw3-bindings
                  init
                  make-context-current
                  set-error-callback
                  set-window-pos-callback
                  set-window-size-callback
                  set-window-close-callback
                  set-window-focus-callback
                  set-window-iconify-callback
                  set-framebuffer-size-callback
                  set-mouse-button-callback
                  set-cursor-enter-callback
                  set-cursor-pos-callback
                  set-scroll-callback
                  set-key-callback
                  set-char-callback
                  set-monitor-callback))

;;; Callbacks
(define window-position-callback (make-parameter (lambda (window x y) #f)))
(define window-size-callback (make-parameter (lambda (window w h) #f)))
(define window-close-callback (make-parameter (lambda (window) #f)))
(define window-refresh-callback (make-parameter (lambda (window) #f)))
(define window-focus-callback (make-parameter (lambda (window focused?) #f)))
(define window-iconify-callback (make-parameter (lambda (window iconified?) #f)))
(define framebuffer-size-callback (make-parameter (lambda (window w h) #f)))
(define mouse-button-callback (make-parameter (lambda (window button action mods) #f)))
(define cursor-position-callback (make-parameter (lambda (window x y) #f)))
(define cursor-enter-callback (make-parameter (lambda (window entered?) #f)))
(define scroll-callback (make-parameter (lambda (window x y) #f)))
(define key-callback (make-parameter (lambda (window key scancode action mods) #f)))
(define char-callback (make-parameter (lambda (window char) #f)))
(define char-mods-callback (make-parameter (lambda (window char mods) #f)))
(define monitor-callback (make-parameter (lambda (monitor event) #f)))
(define joystick-callback (make-parameter (lambda (joystick event) #f)))


(define-external (glfw3WindowPositionCallback (c-pointer window) (int x) (int y))
    void
  ((window-position-callback) window x y))

(define-external (glfw3WindowSizeCallback (c-pointer window) (int w) (int h))
    void
  ((window-size-callback) window w h))

(define-external (glfw3WindowCloseCallback (c-pointer window))
    void
  ((window-close-callback) window))

(define-external (glfw3WindowRefreshCallback (c-pointer window))
    void
  ((window-refresh-callback) window))

(define-external (glfw3WindowFocusCallback (c-pointer window) (bool focused?))
    void
  ((window-focus-callback) window focused?))

(define-external (glfw3WindowIconifyCallback (c-pointer window) (bool iconified?))
    void
  ((window-iconify-callback) window iconified?))

(define-external (glfw3FramebufferSizeCallback (c-pointer window) (int w) (int h))
    void
  ((framebuffer-size-callback) window w h))

(define-external (glfw3MouseButtonCallback (c-pointer window) (int button)
                                           (int action) (int mods))
    void
  ((mouse-button-callback) window button action mods))

(define-external (glfw3CursorPositionCallback (c-pointer window)
                                              (double x) (double y))
    void
  ((cursor-position-callback) window x y))

(define-external (glfw3CursorEnterCallback (c-pointer window) (bool entered?))
    void
  ((cursor-enter-callback) window entered?))

(define-external (glfw3ScrollCallback (c-pointer window)
                                       (double x) (double y))
    void
  ((scroll-callback) window x y))

(define-external (glfw3KeyCallback (c-pointer window) (int key) (int scancode)
                                   (int action) (int mods))
    void
  ((key-callback) window key scancode action mods))

(define-external (glfw3CharCallback (c-pointer window) (unsigned-int char))
    void
  ((char-callback) window char))

(define-external (glfw3CharModsCallback (c-pointer window) (unsigned-int char) (int mods))
    void
  ((char-mods-callback) window char mods))

;; TODO Drop Callback (convert c-string array to list of strings)

(define-external (glfw3MonitorCallback (c-pointer window) (int event))
    void
  ((monitor-callback) window event))

(define-external (glfw3JoystickCallback (int joystick) (int event))
    void
  ((joystick-callback) joystick event))

(define (set-monitor-callback! #!optional callback)
  (%set-monitor-callback (or callback #$glfw3MonitorCallback)))

(define (set-joystick-callback! #!optional callback)
  (%set-joystick-callback (or callback #$glfw3JoystickCallback)))

(define (set-window-position-callback! #!optional win callback)
  (%set-window-pos-callback (or win (window))
                            (or callback #$glfw3WindowPositionCallback)))

(define (set-window-size-callback! #!optional win callback)
  (%set-window-size-callback (or win (window))
                             (or callback #$glfw3WindowSizeCallback)))

(define (set-window-close-callback! #!optional win callback)
  (%set-window-close-callback (or win (window))
                              (or callback #$glfw3WindowCloseCallback)))

(define (set-window-focus-callback! #!optional win callback)
  (%set-window-focus-callback (or win (window))
                              (or callback #$glfw3WindowFocusCallback)))

(define (set-window-iconify-callback! #!optional win callback)
  (%set-window-iconify-callback (or win (window))
                                (or callback #$glfw3WindowIconifyCallback)))

(define (set-framebuffer-size-callback! #!optional win callback)
  (%set-framebuffer-size-callback (or win (window))
                                  (or callback #$glfw3FramebufferSizeCallback)))

(define (set-mouse-button-callback! #!optional win callback)
  (%set-mouse-button-callback (or win (window))
                              (or callback #$glfw3MouseButtonCallback)))

(define (set-cursor-enter-callback! #!optional win callback)
  (%set-cursor-enter-callback (or win (window))
                              (or callback #$glfw3CursorEnterCallback)))

(define (set-cursor-position-callback! #!optional win callback)
  (%set-cursor-pos-callback (or win (window))
                            (or callback #$glfw3CursorPositionCallback)))

(define (set-scroll-callback! #!optional win callback)
  (%set-scroll-callback (or win (window))
                        (or callback #$glfw3ScrollCallback)))

(define (set-key-callback! #!optional win callback)
  (%set-key-callback (or win (window))
                     (or callback #$glfw3KeyCallback)))

(define (set-char-callback! #!optional win callback)
  (%set-char-callback (or win (window))
                      (or callback #$glfw3CharCallback)))

(define (set-char-mods-callback! #!optional win callback)
  (%set-char-mods-callback (or win (window))
                           (or callback #$glfw3CharModsCallback)))

;;; Aliases
(define set-window-position %set-window-pos)
(define get-window-position %get-window-pos)
(define get-monitor-position %get-monitor-pos)
(define set-cursor-position %set-cursor-pos)
(define get-cursor-position %get-cursor-pos)
(define window-should-close? %window-should-close)

;; Error callback in C, rather than Scheme so not all GLFW foreign-lambdas
;; need to be safe
(foreign-declare
"#include <GLFW/glfw3.h>
void errorCallback(int error, const char* description){
     fprintf(stderr, \"GLFW error: %s\\n\", description);
}")

;;; Initialization and window creation
(define (init)
  (foreign-code "glfwSetErrorCallback((GLFWerrorfun) errorCallback);")
  (%init))

(define window (make-parameter #f))

(define (make-context-current win)
  (window win)
  (%make-context-current win))

(define (make-window w h name . hints)
  (define *hints*
    `((resizable: ,+resizable+ bool:)
      (visible: ,+visible+ bool:)
      (decorated: ,+decorated+ bool:)
      (red-bits: ,+red-bits+) (green-bits: ,+green-bits+) (blue-bits: ,+blue-bits+)
      (alpha-bits: ,+alpha-bits+)
      (depth-bits: ,+depth-bits+) (stencil-bits: ,+stencil-bits+)
      (accum-red-bits: ,+accum-red-bits+) (accum-green-bits: ,+accum-green-bits+)
      (accum-blue-bits: ,+accum-blue-bits+) (accum-alpha-bits: ,+accum-alpha-bits+)
      (aux-buffers: ,+aux-buffers+)
      (samples: ,+samples+)
      (refresh-rate: ,+refresh-rate+)
      (stereo: ,+stereo+ bool:)
      (srgb-capable: ,+srgb-capable+ bool:)
      (client-api: ,+client-api+)
      (context-version-major: ,+context-version-major+)
      (context-version-minor: ,+context-version-minor+)
      (context-robustness: ,+context-robustness+)
      (opengl-forward-compat: ,+opengl-forward-compat+ bool:)
      (opengl-debug-context: ,+opengl-debug-context+ bool:)
      (opengl-profile: ,+opengl-profile+)))
  (%default-window-hints)
  (let loop ((hints hints))
    (when (>= (length hints) 2)
      (let* ((key (car hints))
             (val (cadr hints))
             (hint (alist-ref key *hints*)))
        (when hint
          (%window-hint (car hint) (if (and (= (length hint) 2)
                                          (eq? (cadr hint) bool:))
                                       (if val 1 0)
                                       val))))
      (loop (cddr hints))))
  (make-context-current (%create-window w h name
                                        (and (get-keyword fullscreen: hints)
                                             (get-primary-monitor))
                                        #f))
  (%swap-interval (get-keyword swap-interval: hints (lambda () 1)))
  (set-monitor-callback!)
  (set-window-position-callback!)
  (set-window-size-callback!)
  (set-window-close-callback!)
  (set-window-focus-callback!)
  (set-window-iconify-callback!)
  (set-framebuffer-size-callback!)
  (set-mouse-button-callback!)
  (set-cursor-enter-callback!)
  (set-cursor-position-callback!)
  (set-scroll-callback!)
  (set-key-callback!)
  (set-char-callback!)
  (window))

(define-syntax with-window
  (syntax-rules ()
    ((_ (w h name . keys) body ...)
     (begin
       (init)
       (make-window w h name . keys)
       body ...
       (%destroy-window (window))
       (%terminate)))))

) ; end glfw3
