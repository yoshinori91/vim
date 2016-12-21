" ====================== basic file setting =============================================
set fenc=utf-8                              " 文字コードはUTF8 
set nobackup                                " バックアップファイルは作成しない 
set noswapfile                              " スワップファイルは作成しない
set autoread                                " 編集中のファイルが変更されたら自動で読直し
set hidden                                  " バッファ編集中その他のファイルを開けるように
set showcmd                                 " 入力中のコマンドをステータスに表示
" ====================== basic display setting ==========================================
set number                                  " 行番号を表示
set virtualedit=onemore                     " 行末の一文字先まで表示
set showmatch                               " 対応する括弧を強調
set laststatus=2                            " ステータスラインを常に表示
set wildmode=list:longest                   " コマンドラインの補完
" ====================== space and tab setting ==========================================
set list listchars=tab:\▸\-                 " タブを可視化
set expandtab                               " Tab文字を半角スペース
set tabstop=2                               " 行頭以外でのTabのスペース幅
set shiftwidth=2                            " 行頭でのTabのスペース幅
" ====================== search setting =================================================
set ignorecase                              " 大文字小文字関係なく検索
set smartcase                               " 大文字が含まれている場合は、区別
set incsearch                               " 順次検索対象文字列にヒットさせる
set wrapscan                                " 最後まで検索したら最初に戻る
set hlsearch                                " 検索対象文字を強調表示
nnoremap <Esc><Esc> :nohlsearch<CR><Esc>    " 検索強調表示を解除
" ====================== save and quit ==================================================
nnoremap ,s :w<CR><ESC>                     " ファイル保存 (Ctrl-S)
nnoremap ,w :q!<CR><ESC>                    " ファイル閉じる (Ctrl-W)
" ====================== color ==========================================================
colorscheme wombat                          " カラースキーマ
syntax on                                   " シンタックス
" ====================== filetype settings ==============================================
filetype on                                             " ファイル別設定をON
filetype indent plugin on                               " ファイル別indent,pluginをON
autocmd BufRead,BufNewFile *.py setfiletype python      " PYTHON
autocmd BufRead,BufNewFile *.rb setfiletype ruby        " RUBY
autocmd BufRead,BufNewFile *.js setfiletype javascript  " JAVASCRIPT


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
