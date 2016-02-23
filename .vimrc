let mapleader = "\<Space>"                                          " LeaderをSpace
let $PATH = $PATH . ':' . expand('/home/pc-0535/Development/bin')

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
"set hlsearch                                                        " 検索結果をハイライトする
set laststatus=2                                                    " ステータスラインを常に表示
set noswapfile                                                      " スワップファイルは作成しない

nnoremap ,w :w<CR>
nnoremap ,q :q<CR>

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

" ==============================================
" ========== easy motion 移動キー設定 ==========
" ==============================================
" Disable default mappings
let g:EasyMotion_do_mapping = 0

" Jump to anywhere you want by just `4` or `3` key strokes without thinking!
" `s{char}{char}{target}`
nmap <Space><Space> <Plug>(easymotion-s2)
xmap <Space><Space> <Plug>(easymotion-s2)

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

NeoBundleFetch 'Shougo/neobundle.vim'                               " neobundle自体をneobundleで管理
NeoBundle 'tpope/vim-fugitive'                                      " Git
NeoBundle 'jeffreyiacono/vim-colors-wombat'                         " カラースキーマ wombat
NeoBundle 'morhetz/gruvbox'                                         " カラースキーマ gruvbox
NeoBundle 'sickill/vim-monokai'                                     " カラースキーマ monokai
NeoBundle 'tomasr/molokai'                                          " カラースキーマ molokai
NeoBundle 'tpope/vim-surround'                                      " surround vim
NeoBundle "Shougo/unite.vim"                                        " Unite
NeoBundle "Shougo/neomru.vim"                                       " Unite open current files
NeoBundle 'vim-scripts/dbext.vim', '18.0'                           " dbext
NeoBundle 'Lokaltog/vim-easymotion'
NeoBundle 'jonathanfilip/vim-lucius'
NeoBundle 'Yggdroot/indentLine'
NeoBundle 'itchyny/lightline.vim'
NeoBundle '29decibel/codeschool-vim-theme'
NeoBundle 'ujihisa/unite-colorscheme'

let g:indentLine_color_gui = '#D6F7FD'

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
" Eclimのショートカット
" ===================================
" タグジャンプ
nnoremap <silent> )j :<C-u>JavaSearchContext<CR>
nnoremap <silent> )i :<C-u>JavaImport<CR>
nnoremap <silent> )c :<C-u>JavaCallHierarchy<CR>

" ===================================
" Haskell
" ===================================
hi ghcmodType ctermbg=green
nnoremap <Space>gt :<C-u>GhcModType<CR>
nnoremap <Space>ga :<C-u>GhcModTypeClear<CR>
nnoremap <Space>gc :<C-u>GhcModCheck<CR>
nnoremap <Space>gl :<C-u>GhcModLint<CR>
nnoremap <Space>gs :<C-u>GhcModSigCodegen<CR>

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

nnoremap <silent><C-e> :NERDTreeToggle<CR>

filetype plugin indent on
syntax on
colorscheme lucius
set background=dark

