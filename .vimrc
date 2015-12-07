" ESCキーのバインド プランクキーボードにしたことにより不要
"noremap <C-j> <esc>
"noremap! <C-j> <esc>

" NERDTreeへのショートカット
nnoremap <silent><C-e> :NERDTreeToggle<CR>

" タブ入力を空白スペースに置き換える(4文字)
set expandtab
set tabstop=4

" 自動インデントでずれる幅
set shiftwidth=4

" ルーラー,行番号を表示
set ruler
set number

" 改行コードを表示する
set list

" 不可視文字を表示する（タブ・スペース）
set listchars=tab:>-,trail:.,eol:↲,extends:>,precedes:<,nbsp:%

"全角スペースをハイライト表示
augroup highlightIdegraphicSpace
    autocmd!
    autocmd Colorscheme * highlight IdeographicSpace term=underline ctermbg=DarkGreen guibg=DarkGreen
    autocmd VimEnter,WinEnter * match IdeographicSpace /　/
augroup END

" タイトルをバッファ名に変更しない
set notitle
set shortmess+=I

" ターミナル接続を高速にする
set ttyfast

" ターミナルで256色表示を使う
set t_Co=256

" 複数ファイルの編集を可能にする
set autoread

" コマンド、検索パターンを50まで保存
set history=50

" バックアップを作成しない
set nobackup

" GUI vim use clipboard
set guioptions+=a
" yankしたテキストをクリップボードに格納
set clipboard=unnamed,autoselect

"  ======== Search  ========
" インクリメンタルサーチを有効にする
set incsearch

" 大文字小文字を区別しない
set ignorecase

" 大文字で検索されたら対象を大文字限定にする
set smartcase

" 検索結果をハイライトする
set hlsearch

" ステータスラインを常に表示
set laststatus=2

" ファイル名表示
"set statusline+=%<%F

" 現在行が全体行の何%目か表示
"set statusline+=[%p%%]

" スワップファイルは作成しない
set noswapfile
" ========== キー設定 ==========
" buffer next previous
nnoremap <silent> bp :bprevious<CR>
nnoremap <silent> bn :bnext<CR>
" ========== 画面分割 キー設定 ==========
nnoremap ss :split<CR>
nnoremap sv :vsplit<CR>
nnoremap sh <C-w>h<CR>
nnoremap sj <C-w>j<CR>
nnoremap sk <C-w>k<CR>
nnoremap sl <C-w>l<CR>
nnoremap su <C-w>K<CR>
nnoremap sd <C-w>J<CR>
nnoremap sr <C-w>r<CR>

" <ESC>hでハイライトをOFFにする
noremap ,a :noh<CR>

noremap ; :

" ========== Neobundle ==========
" ========== Neobundle ==========
" bundleで管理するディレクトリを指定
set runtimepath+=~/.vim/bundle/neobundle.vim/

" Required:
call neobundle#begin(expand('~/.vim/bundle/'))

" neobundle自体をneobundleで管理
NeoBundleFetch 'Shougo/neobundle.vim'

NeoBundle 'tpope/vim-fugitive'
" カラースキーマ
NeoBundle 'jeffreyiacono/vim-colors-wombat'
NeoBundle 'morhetz/gruvbox'
NeoBundle 'sickill/vim-monokai'
NeoBundle 'tomasr/molokai'
" CTRP
NeoBundle 'ctrlpvim/ctrlp.vim'
" Unite
NeoBundle "Shougo/unite.vim"
" Unite open current files
NeoBundle "Shougo/neomru.vim"
" vimproc
NeoBundle 'Shougo/vimproc', {
  \ 'build' : {
    \ 'windows' : 'make -f make_mingw32.mak',
    \ 'cygwin' : 'make -f make_cygwin.mak',
    \ 'mac' : 'make -f make_mac.mak',
    \ 'unix' : 'make -f make_unix.mak',
  \ },
  \ }
"インデントガイド
NeoBundle 'nathanaelkane/vim-indent-guides'

NeoBundleLazy 'ervandew/eclim', {'build': {'mac': 'ant -Declipse.home=/opt/homebrew-cask/Caskroom/eclipse-java/4.4.0/eclipse -Dvim.files='.escape(expand('~/.bundle/eclim'), '')}}
    autocmd FileType java NeoBundleSource eclim

" NERDTreeを設定
NeoBundle 'scrooloose/nerdtree'

call neobundle#end()

" 未インストールのプラグインがある場合、インストールするかどうかを尋ねてくれるようにする設定
" 毎回聞かれると邪魔な場合もあるので、この設定は任意です。
NeoBundleCheck

" ========== プラグイン設定 ==========
" ========== プラグイン設定 ==========
"vim-indent-guides
let g:indent_guides_guide_size = 1
let g:indent_guides_enable_on_vim_startup=2
let g:indent_guides_auto_colors = 0
    autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd  guibg=#444433 ctermbg=230
    autocmd VimEnter,Colorscheme * :hi IndentGuidesEven guibg=#333344 ctermbg=240

" http://blog.remora.cx/2010/12/vim-ref-with-unite.html
" =================================== 
"  Unit.vimの設定
" =================================== 
" 入力モードで開始する
let g:unite_enable_start_insert=1
" バッファ一覧
noremap <C-P> :Unite buffer<CR>
" ファイル一覧
nnoremap <C-N> :Unite file find ./ -name=file<CR>
" 最近使ったファイルの一覧
nnoremap <silent> ,,u :Unite file<CR>
nnoremap <silent> ,,f :Unite find<CR>
nnoremap <silent> ,,m :Unite file_mru<CR>
nnoremap <silent> ,,b :Unite buffer<CR>
nnoremap <silent> ,,r :Unite -buffer-name=register register<CR>
" grep検索
nnoremap <silent> ,s :<C-u>Unite grep:. -buffer-name=search-buffer<CR>
" カーソル位置の単語をgrep検索
nnoremap <silent> ,sg :<C-u>Unite grep:. -buffer-name=search-buffer<CR><C-R><C-W>

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
