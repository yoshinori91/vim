" ====================== basic file setting =============================================
set fenc=utf-8                              " 文字コードはUTF8 
set nobackup                                " バックアップファイルは作成しない 
set noswapfile                              " スワップファイルは作成しない
set autoread                                " 編集中のファイルが変更されたら自動で読直し
set hidden                                  " バッファ編集中その他のファイルを開けるように
set showcmd                                 " 入力中のコマンドをステータスに表示
" 改行時、上列のコメント文字を引き継がないように設定
augroup auto_comment_off
    autocmd!
    autocmd BufEnter * setlocal formatoptions-=r
    autocmd BufEnter * setlocal formatoptions-=o
augroup END
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
" ====================== [color] ========================================================
colorscheme wombat                          " カラースキーマ
syntax on                                   " シンタックス
" ====================== <file type> ====================================================
filetype on                                             " ファイル別設定をON
filetype indent plugin on                               " ファイル別indent,pluginをON
autocmd BufRead,BufNewFile *.py setfiletype python      " PYTHON
autocmd BufRead,BufNewFile *.rb setfiletype ruby        " RUBY
autocmd BufRead,BufNewFile *.js setfiletype javascript  " JAVASCRIPT
" ====================== split window ===================================================
nnoremap ss :split<CR>                      " 画面を水平に分割
nnoremap sv :vsplit<CR>                     " 画面を垂直に分割
nnoremap si <C-w>_<CR>                      " 分割画面を最大表示
nnoremap so <C-w>=<CR>                      " 最大表示した画面を戻す
nnoremap sh <C-w>h<CR>                      " 左の分割画面に移動
nnoremap sj <C-w>j<CR>                      " 下の分割画面に移動
nnoremap sk <C-w>k<CR>                      " 上の分割画面に移動
nnoremap sl <C-w>l<CR>                      " 右の分割画面に移動
" ====================== [<ctrlp>] ======================================================
" 検索をAGに変更する
if executable('ag')
  let g:ctrlp_use_caching=0
    let g:ctrlp_user_command='ag %s -i --nocolor --nogroup -g ""'
endif
nnoremap <Space><Space> :<C-u>CtrlPMixed<CR>          "<Space>*2 で起動
" 検索対象外をファイルを設定するには、~/.agignore に設定


let g:ctrlp_map = '<Nop>'
nnoremap <silent> <Space><Space> :<C-u>CtrlP<CR>
nnoremap <silent> <Space>b :<C-u>CtrlPBuffer<CR>
