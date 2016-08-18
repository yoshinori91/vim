set list
set number
set expandtab
set tabstop=4
set shiftwidth=4
set listchars=tab:>-,trail:.,eol:↲,extends:>,precedes:<,nbsp:%

set autoread
set history=200
set nobackup
set guioptions+=a

"  ======== Search ========
set incsearch
set ignorecase
set smartcase
set hlsearch
set laststatus=2
set noswapfile

" ESC2回でハイライトを消す
nmap <silent> <Esc><Esc> :nohlsearch<CR>

nnoremap ,w :w<CR>
nnoremap ,q :q<CR>

tnoremap <silent> <ESC> <C-\><C-n>
nnoremap <silent> <Space>t :terminal<CR>

" ========== 画面分割 キー設定 ==========
nnoremap si <C-w>_<CR>
nnoremap so <C-w>=<CR>
nnoremap ss :split<CR>
nnoremap sv :vsplit<CR>
nnoremap sh <C-w>h<CR>
nnoremap sj <C-w>j<CR>
nnoremap sk <C-w>k<CR>
nnoremap sl <C-w>l<CR>
nnoremap su <C-w>K<CR>
nnoremap sd <C-w>J<CR>
nnoremap sr <C-w>r<CR>

nnoremap <silent><C-e> :NERDTreeToggle<CR>

"unite general settings
"インサートモードで開始
let g:unite_enable_start_insert = 1

" 大文字小文字を区別しない
let g:unite_enable_ignore_case = 1
let g:unite_enable_smart_case = 1

" grep検索
nnoremap <silent> <Space>g  :<C-u>Unite grep:. -buffer-name=search-buffer<CR>

" unite grep に ag(The Silver Searcher) を使う
if executable('ag')
  let g:unite_source_grep_command = 'ag'
  let g:unite_source_grep_default_opts = '--nogroup --nocolor --column'
  let g:unite_source_grep_recursive_opt = ''
endif

syntax enable
colorscheme rdark

let g:ctrlp_map = '<Nop>'
nnoremap <silent> <Space><Space> :<C-u>CtrlP<CR>
nnoremap <silent> <Space>b :<C-u>CtrlPBuffer<CR>
