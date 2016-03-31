"let mapleader = "\<Space>"                                          " LeaderをSpace
let $PATH = $PATH . ':' . expand('/home/pc-0535/Development/bin')

norema s <nop>
noremap ; :

set cursorline
set list
set ruler
set number
set expandtab
set tabstop=4
set shiftwidth=4
set listchars=tab:>-,trail:.,eol:↲,extends:>,precedes:<,nbsp:%
set notitle
set shortmess+=I
set ttyfast
set t_Co=256
set autoread
set history=200
set nobackup
set guioptions+=a
set clipboard=unnamed,autoselect


"  ======== Search ========
set incsearch
set ignorecase
set smartcase
set hlsearch
set laststatus=1
set noswapfile

nnoremap ,w :w<CR>
nnoremap ,s :q<CR>
nnoremap ,z :q!<CR>

noremap j gj
noremap k gk
noremap <Down> gj
noremap <Up>   gk

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

nnoremap tt :tabnew<CR>
nnoremap tn gt

" ==============================================
" ========== easy motion 移動キー設定 ==========
" ==============================================
" Disable default mappings
let g:EasyMotion_do_mapping = 0
let g:EasyMotion_smartcase = 1

" Jump to anywhere you want by just `4` or `3` key strokes without thinking!
" `s{char}{char}{target}`
nmap <Space> <Plug>(easymotion-s2)
xmap <Space> <Plug>(easymotion-s2)

" Jump to first match with enter & space
let g:EasyMotion_enter_jump_first = 1
let g:EasyMotion_space_jump_first = 1

" `JK` Motions: Extend line motions
map J <Plug>(easymotion-j)
map K <Plug>(easymotion-k)

" Extend search motions with vital-over command line interface
" Incremental highlight of all the matches
" Now, you don't need to repetitively press `n` or `N` with EasyMotion feature
" `<Tab>` & `<S-Tab>` to scroll up/down a page of next match
" :h easymotion-command-line

" 全角スペースをハイライト表示
augroup highlightIdegraphicSpace
    autocmd!
    autocmd Colorscheme * highlight IdeographicSpace term=underline ctermbg=DarkGreen guibg=DarkGreen
    autocmd VimEnter,WinEnter * match IdeographicSpace /　/
augroup END

" <ESC>hでハイライトをOFFにする
noremap ,a :noh<CR>

" ========== Neobundle ==========
" bundleで管理するディレクトリを指定
" ===============================
set runtimepath+=~/.vim/vundle.git/
call vundle#rc()

set runtimepath+=~/.vim/bundle/neobundle.vim/
" Required:
call neobundle#begin(expand('~/.vim/bundle/'))

NeoBundleFetch 'Shougo/neobundle.vim'
NeoBundle 'tpope/vim-fugitive'
NeoBundle 'jeffreyiacono/vim-colors-wombat'
NeoBundle 'morhetz/gruvbox'
NeoBundle 'sickill/vim-monokai'
NeoBundle 'tomasr/molokai'
NeoBundle 'tpope/vim-surround'
NeoBundle "Shougo/unite.vim"
NeoBundle "Shougo/neomru.vim"
NeoBundle 'Lokaltog/vim-easymotion'
NeoBundle 'jonathanfilip/vim-lucius'
NeoBundle 'Yggdroot/indentLine'
NeoBundle 'itchyny/lightline.vim'
NeoBundle 'ujihisa/unite-colorscheme'
NeoBundle '29decibel/codeschool-vim-theme'
NeoBundle 'sorah/unite-ghq'
NeoBundle 'cocopon/colorswatch.vim'
NeoBundle 'cocopon/lightline-hybrid.vim'

NeoBundle 'nixprime/cpsm'
NeoBundle 'ctrlpvim/ctrlp.vim'

let g:ctrlp_match_func = {'match': 'cpsm#CtrlPMatch'}
" ----------- Haskell関連 -----------
NeoBundle 'kana/vim-filetype-haskell'
NeoBundle 'eagletmt/ghcmod-vim'
NeoBundle 'Shougo/neocomplcache'
NeoBundle 'ujihisa/neco-ghc'
NeoBundle 'thinca/vim-quickrun'
NeoBundle 'osyo-manga/vim-watchdogs'
NeoBundle 'thinca/vim-ref'
NeoBundle 'ujihisa/ref-hoogle'
NeoBundle 'ujihisa/unite-haskellimport'

" Disable haskell-vim omnifunc
let g:haskellmode_completion_ghc = 0
autocmd FileType haskell setlocal omnifunc=necoghc#omnifunc
let g:ycm_semantic_triggers = {'haskell' : ['.']}

let java_highlight_all=1

" vimproc
NeoBundle 'Shougo/vimproc', {
  \ 'build' : {
    \ 'windows' : 'make -f make_mingw32.mak',
    \ 'cygwin' : 'make -f make_cygwin.mak',
    \ 'mac' : 'make -f make_mac.mak',
    \ 'unix' : 'make -f make_unix.mak',
  \ },
  \ }

NeoBundleLazy 'ervandew/eclim', {'build': {'mac': 'ant -Declipse.home=/opt/homebrew-cask/Caskroom/eclipse-java/4.4.0/eclipse -Dvim.files='.escape(expand('~/.bundle/eclim'), '')}}
    autocmd FileType java NeoBundleSource eclim

call neobundle#end()

" 未インストールのプラグインがある場合、インストールするかどうかを尋ねてくれるようにする設定
" 毎回聞かれると邪魔な場合もあるので、この設定は任意です。
NeoBundleCheck

" http://blog.remora.cx/2010/12/vim-ref-with-unite.html
" =================================== 
"  Unit.vimの設定
" =================================== 
" 入力モードで開始する
let g:unite_enable_start_insert=1

"prefix keyの設定
nmap s [unite]

"バッファを表示
nnoremap <silent> [unite]b :<C-u>Unite<Space>buffer<CR>
"レジストリを表示
nnoremap <silent> [unite]r :<C-u>Unite<Space>register<CR>
"タブを表示
nnoremap <silent> [unite]t :<C-u>Unite<Space>tab<CR>
"ヒストリ/ヤンクを表示
nnoremap <silent> [unite]h :<C-u>Unite<Space>history/yank<CR>
"outline
nnoremap <silent> [unite]o :<C-u>Unite<Space>outline<CR>
" grep検索
nnoremap <silent> [unite]g :<C-u>Unite grep:. -buffer-name=search-buffer<CR>

" ===================================
" unite-grep のバックエンドをagに切替
" ===================================
let g:unite_source_grep_command = 'ag'
let g:unite_source_grep_default_opts = '--nocolor --nogroup'
let g:unite_source_grep_recursive_opt = ''
let g:unite_source_grep_max_candidates = 200

" =================================== 
"  indentLine.vimの設定
" =================================== 
let g:indentLine_color_gui = '#797c91'

" ===================================
" Eclimのショートカット
" ===================================
" タグジャンプ
nnoremap <silent> )j :<C-u>JavaSearchContext<CR>
nnoremap <silent> )i :<C-u>JavaImport<CR>
nnoremap <silent> )c :<C-u>JavaCallHierarchy<CR>
nnoremap <silent> )b :<C-u>JavaDebugBreakpointToggle<CR>
nnoremap <silent> )n :<C-u>JavaDebugStep over<CR>

" ===================================
" Haskell
" ===================================
"hi ghcmodType ctermbg = green
"nnoremap <Space>gt :<C-u>GhcModType<CR>
"nnoremap <Space>ga :<C-u>GhcModTypeClear<CR>
"nnoremap <Space>gc :<C-u>GhcModCheck<CR>
"nnoremap <Space>gl :<C-u>GhcModLint<CR>
"nnoremap <Space>gs :<C-u>GhcModSigCodegen<CR>

" fugitive git bindings
nnoremap <silent>fa :Git add %:p<CR><CR>
nnoremap <silent>fs :Gstatus<CR>
nnoremap <silent>fc :Gcommit -v -q<CR>
nnoremap <silent>ft :Gcommit -v -q %:p<CR>
nnoremap <silent>fd :Gdiff -y<CR>
nnoremap <silent>fe :Gedit<CR>
nnoremap <silent>fr :Gread<CR>
nnoremap <silent>fw :Gwrite<CR><CR>
nnoremap <silent>fp :Ggrep<Space>
nnoremap <silent>fm :Gmove<Space>
nnoremap <silent>fb :Git branch<Space>
nnoremap <silent>fo :Git checkout<Space>
nnoremap <silent>fl :Gblame<CR>
nnoremap <silent>fgps :Dispatch! git push<CR>
nnoremap <silent>fgpl :Dispatch! git pull<CR>

nnoremap <silent><C-t> :NERDTreeToggle<CR>
nnoremap <silent><C-s> :CtrlPMixed<CR>

set diffopt+=vertical
let g:ctrlp_use_caching = 0

" 検索ウィンドウの設定
" :help g:ctrlp_match_window
let g:ctrlp_match_window = 'bottom,order:ttb,min:2,max:20,results:50'

if executable('ag')
    set grepprg=ag\ --nogroup\ --nocolor

    let g:ctrlp_user_command = 'ag %s -l --nocolor -g ""'
else
  let g:ctrlp_user_command = ['.git', 'cd %s && git ls-files . -co --exclude-standard', 'find %s -type f']
  let g:ctrlp_prompt_mappings = {
    \ 'AcceptSelection("e")': ['<space>', '<cr>', '<2-LeftMouse>'],
    \ }
endif

let g:ctrlp_cache_dir = '/home/pc-0535/projects/sma-app'

filetype plugin indent on
syntax on
colorscheme negibat
set background=dark

let g:lightline = {
      \ 'colorscheme': 'powerline',
      \ 'mode_map': { 'c': 'NORMAL' },
      \ 'active': {
      \   'left': [ [ 'mode', 'paste' ], [ 'fugitive', 'filename' ] ]
      \ },
      \ 'component_function': {
      \   'modified': 'LightLineModified',
      \   'readonly': 'LightLineReadonly',
      \   'fugitive': 'LightLineFugitive',
      \   'filename': 'LightLineFilename',
      \   'fileformat': 'LightLineFileformat',
      \   'filetype': 'LightLineFiletype',
      \   'fileencoding': 'LightLineFileencoding',
      \   'mode': 'LightLineMode',
      \ },
      \ }

function! LightLineModified()
  return &ft =~ 'help\|vimfiler\|gundo' ? '' : &modified ? '+' : &modifiable ? '' : '-'
endfunction

function! LightLineReadonly()
  return &ft !~? 'help\|vimfiler\|gundo' && &readonly ? '⭤' : ''
endfunction

function! LightLineFilename()
  return ('' != LightLineReadonly() ? LightLineReadonly() . ' ' : '') .
        \ (&ft == 'vimfiler' ? vimfiler#get_status_string() :
        \  &ft == 'unite' ? unite#get_status_string() :
        \  &ft == 'vimshell' ? vimshell#get_status_string() :
        \ '' != expand('%:t') ? expand('%:t') : '[No Name]') .
        \ ('' != LightLineModified() ? ' ' . LightLineModified() : '')
endfunction

function! LightLineFugitive()
  if &ft !~? 'vimfiler\|gundo' && exists("*fugitive#head")
    let _ = fugitive#head()
    return strlen(_) ? '⭠ '._ : ''
  endif
  return ''
endfunction

function! LightLineFileformat()
  return winwidth(0) > 70 ? &fileformat : ''
endfunction

function! LightLineFiletype()
  return winwidth(0) > 70 ? (strlen(&filetype) ? &filetype : 'no ft') : ''
endfunction

function! LightLineFileencoding()
  return winwidth(0) > 70 ? (strlen(&fenc) ? &fenc : &enc) : ''
endfunction

function! LightLineMode()
  return winwidth(0) > 60 ? lightline#mode() : ''
endfunction

