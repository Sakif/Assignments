
;;; Code:
(package-initialize)

(custom-set-variables
 '(auto-package-update-delete-old-versions t)
 '(column-number-mode t)
 '(cua-mode t nil (cua-base))
 '(custom-enabled-themes (quote (tango-dark)))
 '(elpy-rpc-python-command "python3")
 '(global-company-mode t)
 '(global-flycheck-mode t)
 '(global-visual-line-mode t)
 '(helm-autoresize-max-height 50)
 '(helm-autoresize-min-height 30)
 '(helm-autoresize-mode t)
 '(helm-buffers-fuzzy-matching t)
 '(helm-echo-input-in-header-line t)
 '(helm-ff-file-name-history-use-recentf t)
 '(helm-ff-search-library-in-sexp t)
 '(helm-mode t)
 '(helm-mode-fuzzy-match t)
 '(helm-move-to-line-cycle-in-source t)
 '(helm-recentf-fuzzy-match t)
 '(helm-scroll-amount 8)
 '(helm-split-window-inside-p t)
 '(inhibit-startup-screen t)
 '(make-backup-files nil)
 '(menu-bar-mode nil)
 '(package-archives
   (quote
    (("gnu" . "http://elpa.gnu.org/packages/")
     ("melpa" . "http://stable.melpa.org/packages/"))))
 '(package-enable-at-startup t)
 '(package-selected-packages (quote (flycheck-irony company-irony cmake-ide helm-projectile auto-package-update elpy)))
 '(python-shell-interpreter "python3")
 '(scroll-all-mode nil)
 '(show-paren-mode t))

(custom-set-faces)

; irony
(add-hook 'c++-mode-hook 'irony-mode)
(add-hook 'c-mode-hook 'irony-mode)
(add-hook 'irony-mode-hook 'irony-cdb-autosetup-compile-options)
(eval-after-load 'flycheck '(add-hook 'flycheck-mode-hook #'flycheck-irony-setup))

; elpy
(elpy-enable)
(add-hook 'python-mode-hook '(lambda() (add-hook 'before-save-hook 'elpy-format-code)))

; helm
(global-unset-key (kbd "C-x c"))
(global-set-key (kbd "M-/") 'company-complete-common-or-cycle)
(global-set-key (kbd "M-x") 'helm-M-x)
(global-set-key (kbd "C-x C-f") 'helm-find-files)
(global-set-key (kbd "M-y") 'helm-show-kill-ring)
(global-set-key (kbd "C-x b") 'helm-mini)
(helm-projectile-on)

; clang formating
(load "/usr/share/emacs/site-lisp/site-start.d/clang-format.el")
(add-hook 'c++-mode-hook '(lambda() (add-hook 'before-save-hook 'clang-format-buffer)))
(add-hook 'c-mode-hook '(lambda() (add-hook 'before-save-hook 'clang-format-buffer)))

; projectile
(require 'projectile)
(define-key projectile-mode-map (kbd "C-c p") 'projectile-command-map)
(projectile-mode +1)

(auto-package-update-maybe)
;;; init.el ends here
