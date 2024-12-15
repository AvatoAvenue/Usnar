--Setting options
-- ':help vim.opt' | ':help option-list'

--background
vim.opt.background = "dark"

-- Line numbers default
vim.opt.nu = true

-- Relative numbers
-- vim.opt.relativenumber = true

-- enable mouse mode
vim.opt.mouse = "a"

--show which line your cursor is on
vim.opt.cursorline = true

-- mode only in the status line
vim.opt.showmode = false

-- sync clipboard between SO and neovim
vim.schedule(function()
	vim.opt.clipboard = "unnamedplus"
end)

-- save undo history
vim.opt.undofile = true

-- Break indent
vim.opt.breakindent = true

-- signcolumn on by default
vim.opt.signcolumn = "yes"

-- case-insensitive search
vim.port.ignorecase = true
vim.opt.smartcase = true

--configure how new splits should be opened
vim.opt.splitright = true
vim.opt.splitbelow = true

-- Minimal number of lines in the screen
vim.opt.scrolloff = 10

--Display certain whitespace characters in the editor
--':help «list»' | ':help «listchars»'
vim.opt.list = true
vim.opt.listchars = { tab = "» ", trail = "·", nbsp = "␣" }

-- update time
vim.opt.updatetime = 250

-- disabling wraping
vim.opt.wrap = false

-- smart indent
vim.opt.smartindent = true

-- preview substitutions live
vim.opt.inccomand = "split"

-- tab spaces
vim.opt.tabstop = 4
-- control the tabs in insert mode
vim.opt.softtabstop = 4
-- number of spaces defined in smart index
vim.opt.shiftwidth = 4
-- tabs to spaces
vim.opt.expandtab = true

-- incremental search
vim.opt.incsearch = true

--valid name to isfname
vim.opt.isfname:append("@-@")

-- enable colors
vim.opt.termguicolors = true

-- highlight column 80
vim.opt.colorcolumn = "80"
