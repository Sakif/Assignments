
;;; Code:
(require 'package)
(add-to-list 'package-archives
             '("MELPA" . "https://stable.melpa.org/packages/") t)
(package-initialize)

; base config
(global-visual-line-mode)
(show-paren-mode)
(column-number-mode)

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(cua-mode t nil (cua-base))
 '(inhibit-startup-screen t)
 '(make-backup-files nil)
 '(menu-bar-mode (display-graphic-p))
 '(package-enable-at-startup t)
 '(package-selected-packages
   (quote
    (auctex iedit markdown-mode latex-extra auctex-latexmk doom-themes doom-modeline helm-projectile elpy company-irony use-package flycheck-irony))))

(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(use-package company
  :config (global-company-mode)
  :bind ("M-/" . company-complete-common-or-cycle))

(use-package flycheck
  :config (global-flycheck-mode))

(use-package helm-projectile
  :init
  (global-unset-key (kbd "C-x c"))
  (setq helm-autoresize-max-height 50)
  (setq helm-autoresize-min-height 30)
  (setq helm-autoresize-mode t)
  (setq helm-buffers-fuzzy-matching t)
  (setq helm-ff-file-name-history-use-recentf t)
  (setq helm-ff-search-library-in-sexp t)
  (setq helm-move-to-line-cycle-in-source t)
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

(use-package elpy
  :init
  (setq python-shell-interpreter "python3")
  (setq elpy-rpc-python-command "python3")
  :config (elpy-enable)
  :hook (before-save . elpy-format-code))

(use-package irony
  :init (load "~/.emacs.d/clang-format.el")
  :hook
  ((c++-mode . irony-mode)
   (c-mode . irony-mode)
   (irony-mode . irony-cdb-autosetup-compile-options))
  :config
  (eval-after-load 'flycheck '(add-hook 'flycheck-mode-hook #'flycheck-irony-setup))
  (add-hook 'before-save-hook 'clang-format-buffer)
  )

(use-package doom-modeline
  :init
  (setq doom-modeline-icon (display-graphic-p))
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

;;; init.el ends here
