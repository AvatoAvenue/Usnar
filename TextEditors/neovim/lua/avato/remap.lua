-- [[ keymaps ]]
-- ':help vim.keymap.set()'

-- key leader
vim.g.mapleader = " "

-- shortcut to Ex
vim.keymap.set("n", "<leader>ge", "vim.cmd.Ex")

-- clear highlights after esc in normal mode
vim.keymap.set("n", "<Esc>", "<cmd>nohlsearch<CR>")
