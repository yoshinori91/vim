set encoding=utf-8
scriptencoding utf-8
" ↑1行目は読み込み時の文字コードの設定
"   l2行目はVim Script内でマルチバイトを使う場合の設定
" Vim scritptにvimrcも含まれるので、日本語でコメントを書く場合は先頭にこの設定が必要になる

"----------------------------------------------------------
" NeoBundle
"----------------------------------------------------------
if has('vim_starting')
    " 初回起動時のみruntimepathにNeoBundleのパスを指定する
    set runtimepath+=~/.vim/bundle/neobundle.vim/
    " NeoBundleが未インストールであればgit cloneする
    if !isdirectory(expand("~/.vim/bundle/neobundle.vim/"))
        echo "install NeoBundle..."
        :call system("git clone git://github.com/Shougo/neobundle.vim ~/.vim/bundle/neobundle.vim")
    endif
endif

call neobundle#begin(expand('~/.vim/bundle/'))

" インストールするVimプラグインを以下に記述
" NeoBundle自身を管理
NeoBundleFetch 'Shougo/neobundle.vim'
" カラースキームmolokai
NeoBundle 'tomasr/molokai'
" カラースキーム atom-dark
NeoBundle 'gosukiwi/vim-atom-dark'
" ステータスラインの表示内容強化
NeoBundle 'itchyny/lightline.vim'
" インデントの可視化
NeoBundle 'Yggdroot/indentLine'
" 末尾の全角半角空白文字を赤くハイライト
NeoBundle 'bronson/vim-trailing-whitespace'
" 括弧を自動挿入
NeoBundle 'cohama/lexima.vim'
" 構文エラーチェック
NeoBundle 'scrooloose/syntastic'
" 多機能セレクタ
NeoBundle 'ctrlpvim/ctrlp.vim'
" CtrlPの拡張プラグイン. 関数検索
NeoBundle 'tacahiroy/ctrlp-funky'
" CtrlPの拡張プラグイン. コマンド履歴検索
NeoBundle 'suy/vim-ctrlp-commandline'
" CtrlPの検索にagを使う
NeoBundle 'rking/ag.vim'
" プロジェクトに入ってるESLintを読み込む
NeoBundle 'pmsorhaindo/syntastic-local-eslint.vim'
" Javascript Syntax
NeoBundle 'othree/yajs.vim'
" Jsx Syntax
NeoBundle 'maxmellon/vim-jsx-pretty'
" Javascript 静的解析＆保管強化
NeoBundle 'marijnh/tern_for_vim', {
  \ 'build': {
  \   'others': 'npm install'
  \}}

" vimのlua機能が使える時だけ以下のVimプラグインをインストールする
if has('lua')
    " コードの自動補完
    NeoBundle 'Shougo/neocomplete.vim'
    " スニペットの補完機能
    NeoBundle "Shougo/neosnippet"
    " スニペット集
    NeoBundle 'Shougo/neosnippet-snippets'
endif

call neobundle#end()

" ファイルタイプ別のVimプラグイン/インデントを有効にする
filetype plugin indent on

" 未インストールのVimプラグインがある場合、インストールするかどうかを尋ねてくれるようにする設定
NeoBundleCheck

"----------------------------------------------------------
" 文字
"----------------------------------------------------------
set fileencoding=utf-8 " 保存時の文字コード
set fileencodings=ucs-boms,utf-8,euc-jp,cp932 " 読み込み時の文字コードの自動判別. 左側が優先される
set fileformats=unix,dos,mac " 改行コードの自動判別. 左側が優先される
set ambiwidth=double " □や○文字が崩れる問題を解決
"----------------------------------------------------------
" スワップ・バックアップファイル
"----------------------------------------------------------
set nobackup                                " バックアップファイルは作成しない
set noswapfile                              " スワップファイルは作成しない
set autoread                                " 編集中のファイルが変更されたら自動で読直し
set hidden                                  " バッファ編集中その他のファイルを開けるように
"----------------------------------------------------------
" タブ・インデント
"----------------------------------------------------------
set list listchars=tab:\▸\- " タブを可視化
set expandtab " タブ入力を複数の空白入力に置き換える
set tabstop=4 " 画面上でタブ文字が占める幅
set softtabstop=4 " 連続した空白に対してタブキーやバックスペースキーでカーソルが動く幅
set autoindent " 改行時に前の行のインデントを継続する
set smartindent " 改行時に前の行の構文をチェックし次の行のインデントを増減する
set shiftwidth=4 " smartindentで増減する幅
"----------------------------------------------------------
" カラースキーム
"----------------------------------------------------------
if neobundle#is_installed('vim-atom-dark')
    colorscheme atom-dark-256 " カラースキームにmolokaiを設定する
endif

set t_Co=256 " iTerm2など既に256色環境なら無くても良い
syntax enable " 構文に色を付ける
"----------------------------------------------------------
" ステータスライン
"----------------------------------------------------------
set laststatus=2 " ステータスラインを常に表示
set showmode " 現在のモードを表示
set showcmd " 打ったコマンドをステータスラインの下に表示
set ruler " ステータスラインの右側にカーソルの位置を表示する
"----------------------------------------------------------
" コマンドモード
"----------------------------------------------------------
set wildmenu " コマンドモードの補完
set history=5000 " 保存するコマンド履歴の数
"----------------------------------------------------------
" 文字列検索
"----------------------------------------------------------
set incsearch " インクリメンタルサーチ. １文字入力毎に検索を行う
set ignorecase " 検索パターンに大文字小文字を区別しない
set smartcase " 検索パターンに大文字を含んでいたら大文字小文字を区別する
set hlsearch " 検索結果をハイライト
set wrapscan " 最後まで検索したら、最初に戻る

" ESCキー2度押しでハイライトの切り替え
nnoremap <silent><Esc><Esc> :<C-u>set nohlsearch!<CR>
"----------------------------------------------------------
" カーソル
"----------------------------------------------------------
set whichwrap=b,s,h,l,<,>,[,],~ " カーソルの左右移動で行末から次の行の行頭への移動が可能になる
set number " 行番号を表示

" 行が折り返し表示されていた場合、行単位ではなく表示行単位でカーソルを移動する
nnoremap j gj
nnoremap k gk
nnoremap <down> gj
nnoremap <up> gk

" バックスペースキーの有効化
set backspace=indent,eol,start
"----------------------------------------------------------
" カッコ・タグの対応
"----------------------------------------------------------
set showmatch " 括弧の対応関係を一瞬表示する
source $VIMRUNTIME/macros/matchit.vim " Vimの「%」を拡張する
"----------------------------------------------------------
" マウスでカーソル移動とスクロール
"----------------------------------------------------------
if has('mouse')
    set mouse=a
    if has('mouse_sgr')
        set ttymouse=sgr
    elseif v:version > 703 || v:version is 703 && has('patch632')
        set ttymouse=sgr
    else
        set ttymouse=xterm2
    endif
endif
"----------------------------------------------------------
" クリップボードからのペースト/改行時にコメントを追加しない
"----------------------------------------------------------
" 挿入モードでクリップボードからペーストする時に自動でインデントさせないようにする
if &term =~ "xterm"
    let &t_SI .= "\e[?2004h"
    let &t_EI .= "\e[?2004l"
    let &pastetoggle = "\e[201~"

    function XTermPasteBegin(ret)
        set paste
        return a:ret
    endfunction

    inoremap <special> <expr> <Esc>[200~ XTermPasteBegin("")
endif

autocmd FileType * setlocal formatoptions-=ro

"----------------------------------------------------------
" Syntastic
"----------------------------------------------------------
" 構文エラー行に「>>」を表示
let g:syntastic_enable_signs = 1
" 他のVimプラグインと競合するのを防ぐ
let g:syntastic_always_populate_loc_list = 1
" 構文エラーリストを非表示
let g:syntastic_auto_loc_list = 0
" ファイルを開いた時に構文エラーチェックを実行する
let g:syntastic_check_on_open = 1
" 「:wq」で終了する時も構文エラーチェックする
let g:syntastic_check_on_wq = 1
" Javascript用. 構文エラーチェックにESLintを使用
let g:syntastic_javascript_checkers=['eslint']
" Javascript以外は構文エラーチェックをしない
let g:syntastic_mode_map = { 'mode': 'passive',
                           \ 'active_filetypes': ['javascript'],
                           \ 'passive_filetypes': [] }
"----------------------------------------------------------
" neocomplete・neosnippetの設定
"----------------------------------------------------------
if neobundle#is_installed('neocomplete.vim')
    " Vim起動時にneocompleteを有効にする
    let g:neocomplete#enable_at_startup = 1
    " smartcase有効化. 大文字が入力されるまで大文字小文字の区別を無視する
    let g:neocomplete#enable_smart_case = 1
    " 3文字以上の単語に対して補完を有効にする
    let g:neocomplete#min_keyword_length = 3
    " 区切り文字まで補完する
    let g:neocomplete#enable_auto_delimiter = 1
    " 1文字目の入力から補完のポップアップを表示
    let g:neocomplete#auto_completion_start_length = 1
    " バックスペースで補完のポップアップを閉じる
    inoremap <expr><BS> neocomplete#smart_close_popup()."<ESC>"
    " <TAB>: completion.
    inoremap <expr><TAB>  pumvisible() ? "\<C-n>" : "\<TAB>"
    inoremap <expr><S-TAB>  pumvisible() ? "\<C-p>" : "\<S-TAB>"
    " Plugin key-mappings.
    imap <C-k> <Plug>(neosnippet_expand_or_jump)
    smap <C-k> <Plug>(neosnippet_expand_or_jump)

    " SuperTab like snippets behavior.
    imap <expr><TAB> neosnippet#jumpable() ? "\<Plug>(neosnippet_expand_or_jump)" : pumvisible() ? "\<C-n>" : "\<TAB>"
    smap <expr><TAB> neosnippet#jumpable() ? "\<Plug>(neosnippet_expand_or_jump)" : "\<TAB>"
    " For snippet_complete marker.
    if has('conceal')
        set conceallevel=2 concealcursor=i
    endif
endif
"----------------------------------------------------------
" CtrlP
"----------------------------------------------------------
" マッチウインドウの設定.下部に表示, 大きさ20行で固定, 検索結果100件
let g:ctrlp_match_window = 'order:ttb,min:20,max:20,results:100'
let g:ctrlp_show_hidden = 1 " .(ドット)から始まるファイルも検索対象にする
let g:ctrlp_types = ['fil'] "ファイル検索のみ使用
" CtrlPの拡張として「funky」と「commandline」を使用
let g:ctrlp_extensions = ['funky', 'commandline']
" CtrlP keymaps

" CtrlPCommandLineの有効化
command! CtrlPCommandLine call ctrlp#init(ctrlp#commandline#id())

" CtrlPFunkyの絞り込み検索設定
let g:ctrlp_funky_matchtype = 'path'

if executable('ag')
  let g:ctrlp_use_caching=0 " CtrlPのキャッシュを使わない
  let g:ctrlp_user_command='ag %s -i --hidden -g ""' " 「ag」の検索設定
endif
" keymaps
let g:ctrlp_map = '<Nop>'
nnoremap <Space>p :<C-u>CtrlP<CR>
nnoremap <Space>b :<C-u>CtrlPBuffer<CR>
nnoremap <Space>m :<C-u>CtrlPMixed<CR>
" --------------------------------------------------------
" キーマップ
" --------------------------------------------------------
" 画面分割
nnoremap ss :split<CR>                      " 画面を水平に分割
nnoremap sv :vsplit<CR>                     " 画面を垂直に分割
nnoremap si <C-w>_<CR>                      " 分割画面を最大表示
nnoremap so <C-w>=<CR>                      " 最大表示した画面を戻す
nnoremap sh <C-w>h<CR>                      " 左の分割画面に移動
nnoremap sj <C-w>j<CR>                      " 下の分割画面に移動
nnoremap sk <C-w>k<CR>                      " 上の分割画面に移動
nnoremap sl <C-w>l<CR>                      " 右の分割画面に移動
" save and quit
nnoremap ,s :w<CR><ESC>                     " ファイル保存 (Ctrl-S)
nnoremap ,w :q!<CR><ESC>                    " ファイル閉じる (Ctrl-W)

