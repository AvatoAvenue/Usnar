-- [[ keymaps ]]
-- ':help vim.keymap.set()'

-- key leader
vim.g.mapleader = " "

-- shortcut to Ex
vim.keymap.set("n", "<leader>te", vim.cmd.Ex)

-- clear highlights after esc in normal mode
vim.keymap.set("n", "<Esc>", "<cmd>nohlsearch<CR>")

--moving lines fast
vim.keymap.set("v", "J", ":m '>+1<CR>gv=gv")
vim.keymap.set("v", "K", ":m '>-2<CR>gv=gv")
vim.keymap.set("v", "<C-Down>", ":m '>+1<CR>gv=gv")
vim.keymap.set("v", "<C-Up>", ":m '>-2<CR>gv=gv")

--lines downward to the same line
vim.keymap.set("n", "J", "mzJ`z")

--move fast idk
vim.keymap.set("n", "<C-d>", "<C-d>zz")
vim.keymap.set("n", "<C-u>", "<C-u>zz")

--move between words
vim.keymap.set("n", "n", "nzzzn")
vim.keymap.set("n", "N", "nzzzv")

--reset lsp
vim.keymap.set("n", "<leader>zig", "<cmd>LspRestart<cr>")

--delete with entering register
vim.keymap.set({ "n", "v" }, "<leader>d", "\"_d")

--format code
vim.keymap.set("n", "<leader>f", vim.lsp.buf.format)

--move between quickfix list
vim.keymap.set("n", "<C-k>", "<cmd>cnext<CR>zz")
vim.keymap.set("n", "<C-j>", "<cmd>cprev<CR>zz")
vim.keymap.set("n", "<leader>k", "<cmd>lnext<CR>zz")
vim.keymap.set("n", "<leader>j", "<cmd>lprev<CR>zz")

--replace words downward the cursor
vim.keymap.set(
	"n",
	"<leader>s",
	[[:%s/\<<C-r><C-w>\>/<C-r><C-w>/gI<Left><Left><Left>]]
)

--exec
vim.keymap.set("n", "<leader>x", "<cmd>!chmod +x %<CR>", { silent = true })

--idk
vim.keymap.set("n", "Q", "<nop>")
