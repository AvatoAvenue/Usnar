require("avato.set")
require("avato.remap")
require("avato.lazy_init")

-- initial colorscheme
vim.cmd 'colorscheme oxocarbon'

local augroup = vim.api.nvim_create_augroup
local avatoGroup = augroup("avato", {})

local autocmd = vim.api.nvim_create_autocmd
local yank_group = augroup('HighlightYank', {})

-- [[ autocommands]]
-- ':help lua-guide-autocommands'

-- highlight when yanking text
-- ':help vim.highlight.on_yank'
autocmd('TextYankPost', {
	group = yank_group,
	pattern = '*',
	callback = function()
		vim.highlight.on_yank({
			higroup = 'IncSearch',
			timeout = 40,
	})
	end
})

autocmd('LspAttach', {
	group = avatoGroup,
	callback = function(e)
		local opts = { buffer = e.buf }
		-- go to definition
		vim.keymap.set("n", "gd", function() vim.lsp.buf.definition() end, opts)
		-- hover with definition
        vim.keymap.set("n", "K", function() vim.lsp.buf.hover() end, opts)
		-- search symbols in a project with the lsp
        vim.keymap.set("n", "<leader>vws", function() vim.lsp.buf.workspace_symbol() end, opts)
		-- diagnostic
        vim.keymap.set("n", "<leader>vd", function() vim.diagnostic.open_float() end, opts)
		-- show actions with fix(maybe not)
        vim.keymap.set("n", "<leader>vca", function() vim.lsp.buf.code_action() end, opts)
		-- show references of the symbol
        vim.keymap.set("n", "<leader>vrr", function() vim.lsp.buf.references() end, opts)
		-- rename the symbol, updating all the references
        vim.keymap.set("n", "<leader>vrn", function() vim.lsp.buf.rename() end, opts)
		-- show signature_help
        vim.keymap.set("i", "<C-h>", function() vim.lsp.buf.signature_help() end, opts)
		-- go to next diagnostic
        vim.keymap.set("n", "[d", function() vim.diagnostic.goto_next() end, opts)
		-- go to previous diagnostic
        vim.keymap.set("n", "]d", function() vim.diagnostic.goto_prev() end, opts)
	end
})
