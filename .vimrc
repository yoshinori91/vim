let mapleader = "\<Space>"                                          " LeaderをSpace

norema s <nop>
noremap ; :

set list                                                            " 改行コードを表示する
set ruler                                                           " ルーラーを表示
set number                                                          " 行番号を表示
set expandtab                                                       " タブ入力を空白スペースに置き換える
set tabstop=4                                                       " タブの空白スペースは４文字とする
set shiftwidth=4                                                    " 自動インデントでずれる幅
set listchars=tab:>-,trail:.,eol:↲,extends:>,precedes:<,nbsp:%      " 不可視文字を表示する（タブ・スペース）
set notitle                                                         " タイトルに変更しない
set shortmess+=I                                                    " タイトルをバッファ名に変更しない
set ttyfast                                                         " ターミナル接続を高速にする
set t_Co=256                                                        " ターミナルで256色表示を使う
set autoread                                                        " 複数ファイルの編集を可能にする
set history=50                                                      " コマンド、検索パターンを50まで保存
set nobackup                                                        " バックアップを作成しない
set guioptions+=a                                                   " GUI vim use clipboard
set clipboard=unnamed,autoselect                                    " yankしたテキストをクリップボードに格納

"  ======== Search ========
set incsearch                                                       " インクリメンタルサーチを有効にする
set ignorecase                                                      " 大文字小文字を区別しない
set smartcase                                                       " 大文字で検索対象を大文字限定にする
set hlsearch                                                        " 検索結果をハイライトする
set laststatus=2                                                    " ステータスラインを常に表示
set noswapfile                                                      " スワップファイルは作成しない

nnoremap ,w :w<CR>
nnoremap ,q :q<CR>

" ========== 全て表示行で移動するため、論理行の移動を削除する
nnoremap j gj
nnoremap k gk
nnoremap gj j
nnoremap gk k
" ========== 画面分割 キー設定 ==========
nnoremap si <C-w>_<CR>                                              " 画面を最大化
nnoremap so <C-w>=<CR>                                              " 画面を最小化
nnoremap ss :split<CR>                                              " 画面を水平に分割
nnoremap sv :vsplit<CR>                                             " 画面を垂直に分割
nnoremap sh <C-w>h<CR>                                              " 左に画面移動
nnoremap sj <C-w>j<CR>                                              " 下に画面移動
nnoremap sk <C-w>k<CR>                                              " 上に画面移動
nnoremap sl <C-w>l<CR>                                              " 右に画面移動
nnoremap su <C-w>K<CR>                                              " 現在の画面を一番上に移動
nnoremap sd <C-w>J<CR>                                              " 現在の画面を一番下に移動
nnoremap sr <C-w>r<CR>                                              " 現在の画面を移動

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
set runtimepath+=~/.vim/bundle/neobundle.vim/
" Required:
call neobundle#begin(expand('~/.vim/bundle/'))

NeoBundleFetch 'Shougo/neobundle.vim'                               " neobundle自体をneobundleで管理
NeoBundle 'tpope/vim-fugitive'                                      " Git
NeoBundle 'jeffreyiacono/vim-colors-wombat'                         " カラースキーマ wombat
NeoBundle 'morhetz/gruvbox'                                         " カラースキーマ gruvbox
NeoBundle 'sickill/vim-monokai'                                     " カラースキーマ monokai
NeoBundle 'tomasr/molokai'                                          " カラースキーマ molokai
NeoBundle 'tpope/vim-surround'                                      " surround vim
NeoBundle "Shougo/unite.vim"                                        " Unite
NeoBundle "Shougo/neomru.vim"                                       " Unite open current files
NeoBundle 'nathanaelkane/vim-indent-guides'                         "インデントガイド
NeoBundle 'scrooloose/nerdtree'                                     " NERDTreeを設定
NeoBundle 'vim-scripts/dbext.vim', '18.0'                           " dbext

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

" ========== vim indent guide 設定==========
"vim-indent-guides
let g:indent_guides_guide_size = 1
let g:indent_guides_enable_on_vim_startup=2
let g:indent_guides_auto_colors = 0
    autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd  guibg=#444433 ctermbg=220
    autocmd VimEnter,Colorscheme * :hi IndentGuidesEven guibg=#333344 ctermbg=240

" http://blog.remora.cx/2010/12/vim-ref-with-unite.html
" =================================== 
"  Unit.vimの設定
" =================================== 
let g:unite_enable_start_insert=1                                                   " 入力モードで開始する
nnoremap <silent> ,u :Unite file<CR>
nnoremap <silent> ,f :Unite find<CR>
nnoremap <silent> ,m :Unite file_mru<CR>
nnoremap <silent> ,b :Unite buffer<CR>
nnoremap <silent> ,r :Unite -buffer-name=register register<CR>
" grep検索
nnoremap <silent> ,d :<C-u>Unite grep:. -buffer-name=search-buffer<CR>
" カーソル位置の単語をgrep検索
nnoremap <silent> ,dg :<C-u>Unite grep:. -buffer-name=search-buffer<CR><C-R><C-W>

" ===================================
" unite-grep のバックエンドをagに切替
" ===================================
let g:unite_source_grep_command = 'ag'
let g:unite_source_grep_default_opts = '--nocolor --nogroup'
let g:unite_source_grep_recursive_opt = ''
let g:unite_source_grep_max_candidates = 200


" ===================================
" DBへの接続情報
" ===================================
let dbext_default_profile=""
let dbext_default_type="PGSQL"
let dbext_default_user="postgres"
let dbext_default_passwd="postgres"
let dbext_default_dbname="sma"
let dbext_default_host="192.168.33.11"
let dbext_default_port="5432"
"vimに表示する行数設定
let dbext_default_buffer_lines=30

" ===================================
" NERDTreeのショートカット
" ===================================
nnoremap <silent><C-e> :NERDTreeToggle<CR>

" ===================================
" Eclimのショートカット
" ===================================
" タグジャンプ
nnoremap <silent> ,jj :<C-u>JavaSearchContext<CR>
nnoremap <silent> ,ji :<C-u>JavaImport<CR>
nnoremap <silent> ,jh :<C-u>JavaCallHierarchy<CR>
nnoremap <silent> ,jb :<C-u>JavaDebugBreakpointToggle<CR>

" fugitive git bindings
nnoremap <silent>,ga :Git add %:p<CR><CR>
nnoremap <silent>,gs :Gstatus<CR>
nnoremap <silent>,gc :Gcommit -v -q<CR>
nnoremap <silent>,gt :Gcommit -v -q %:p<CR>
nnoremap <silent>,gd :Gdiff<CR>
nnoremap <silent>,ge :Gedit<CR>
nnoremap <silent>,gr :Gread<CR>
nnoremap <silent>,gw :Gwrite<CR><CR>
nnoremap <silent>,gl :silent! Glog<CR>:bot copen<CR>
nnoremap <silent>,gp :Ggrep<Space>
nnoremap <silent>,gm :Gmove<Space>
nnoremap <silent>,gb :Git branch<Space>
nnoremap <silent>,go :Git checkout<Space>
nnoremap <silent>,gps :Dispatch! git push<CR>
nnoremap <silent>,gpl :Dispatch! git pull<CR>

filetype plugin indent on
syntax on
colorscheme wombat
set background=dark

" ===================================
"挿入モード時、ステータスラインの色を変更
" ===================================
let g:hi_insert = 'highlight StatusLine guifg=darkblue guibg=darkyellow gui=none ctermfg=blue ctermbg=yellow cterm=none'

if has('syntax')
  augroup InsertHook
    autocmd!
    autocmd InsertEnter * call s:StatusLine('Enter')
    autocmd InsertLeave * call s:StatusLine('Leave')
  augroup END
endif

let s:slhlcmd = ''
function! s:StatusLine(mode)
  if a:mode == 'Enter'
    silent! let s:slhlcmd = 'highlight ' . s:GetHighlight('StatusLine')
    silent exec g:hi_insert
  else
    highlight clear StatusLine
    silent exec s:slhlcmd
  endif
endfunction

function! s:GetHighlight(hi)
  redir => hl
  exec 'highlight '.a:hi
  redir END
  let hl = substitute(hl, '[\r\n]', '', 'g')
  let hl = substitute(hl, 'xxx', '', '')
  return hl
endfunction

