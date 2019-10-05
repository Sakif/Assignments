
;;; Code:
(package-initialize)

(use-package elpy
  :init
  (setq python-shell-interpreter "python3")
  (setq elpy-rpc-python-command "python3")
  :config
  (elpy-enable)
  :hook (before-save . elpy-format-code))

(use-package company
  :config
  (global-company-mode t)
  :bind ("M-/" . company-complete-common-or-cycle))

(use-package irony
  :hook
  ((c++-mode . irony-mode)
   (c-mode . irony-mode)
   (irony-mode . irony-cdb-autosetup-compile-options))
  :config
  (eval-after-load 'flycheck '(add-hook 'flycheck-mode-hook #'flycheck-irony-setup)))

(use-package flycheck
  :config
  (global-flycheck-mode t))

(use-package helm-projectile
  :init
  (global-unset-key (kbd "C-x c"))
  (setq helm-autoresize-max-height 50)
  (setq helm-autoresize-min-height 30)
  (setq helm-autoresize-mode t)
  (setq helm-buffers-fuzzy-matching t)
  (setq helm-ff-file-name-history-use-recentf t)
  (setq helm-ff-search-library-in-sexp t)
  (setq helm-mode-fuzzy-match t)
  (setq helm-move-to-line-cycle-in-source t)
  (setq helm-recentf-fuzzy-match t)
  (setq helm-scroll-amount 8)
  (setq helm-split-window-inside-p t)
  :config
  (setq helm-mode t)
  (helm-projectile-on)
  (projectile-mode +1)
  :bind
  (("M-x" . helm-M-x)
   ("C-x b" . helm-mini)
   ("M-y" . helm-show-kill-ring)
   ("C-x C-f" . helm-find-files)))

(use-package doom-modeline
  :init
  (setq doom-modeline-icon (display-graphic-p));(display-graphic-p)
  (setq doom-modeline-major-mode-icon t)
  (setq doom-modeline-buffer-state-icon t)
  (setq doom-modeline-buffer-file-name-style 'file-name)
  (setq doom-modeline-buffer-modification-icon t)
  (setq doom-modeline-minor-modes (featurep 'minions))
  :hook (after-init . doom-modeline-mode))

(use-package doom-themes
  :config
  (doom-themes-visual-bell-config)
  (load-theme 'doom-one t))

(use-package auto-package-update
  :init
  (setq auto-package-update-delete-old-versions t)
  :config
  (auto-package-update-maybe))

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(column-number-mode t)
 '(cua-mode t nil (cua-base))
 '(global-visual-line-mode t)
 '(inhibit-startup-screen t)
 '(make-backup-files nil)
 '(menu-bar-mode nil)
 '(package-archives
   (quote
    (("gnu" . "http://elpa.gnu.org/packages/")
     ("melpa" . "http://stable.melpa.org/packages/"))))
 '(package-enable-at-startup t)
 '(package-selected-packages (quote (flycheck-irony use-package company-irony)))
 '(scroll-all-mode nil)
 '(show-paren-mode t))

;;; init.el ends here
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
