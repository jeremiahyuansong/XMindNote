# linux 常规配置

## ~/.bashrc配置

```bash
alias updatedb='/usr/libexec/locate.updatedb'
export PATH="$PATH:$HOME/.ft"
# Tell ls to be colourful
export CLICOLOR=1
export LSCOLORS=Exfxcxdxbxegedabagacad
# Tell grep to highlight matches
export GREP_OPTIONS='--color=auto'

export TERM="xterm-color"
# 显示抬头的内容
PS1='\[\e[0;33m\]Ubuntu-\[\e[0;33m\]\u\[\e[0m\]@\[\e[0;32m\]\h\[\e[0m\]:\[\e[0;34m\]\w\[\e[0m\]\$ '
```

## ~/.vimrc配置
vim的配置参考git上的这个[项目](https://github.com/gavin66/g-vim)进行配置，后续有一些自己变动的注释中以leslieyuan标注出来，拒绝折腾，vim一切从简。
```bash
" notes {
"   Author: yuansong 
"   Version: 0.1.0
"   Email: jeremiah_yuan@163.com
" }

" Initialize the plugin 初始化插件 {
    if filereadable(expand("~/.vimrc.bundles"))
      source ~/.vimrc.bundles
    endif
" }

" General 一般通用设置 {
    " 修改 leader 键(前缀键)
    let mapleader = ','
    let g:mapleader = ','

    " 文件修改后自动载入
    set autoread

    " 启用鼠标
    "set mouse=a
    " 不启用鼠标
    set mouse-=a

    " 保存命令行历史500条
    set history=500

    " 取消备份
    set nobackup

    " 关闭交换文件
    set noswapfile

    " 搜索正则匹配规则改变 见帮助 :h magic
    set magic

    " encoding 文件编码,格式 {
        " 设置文件格式
        set encoding=utf-8
        " 自动判断编码,依次尝试以下编码
        set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1
        set helplang=cn
        " 影响普通模式下的 vim
        set termencoding=utf-8
        set ffs=unix,dos,mac

        " 如遇Unicode值大于255的文本，不必等到空格再折行
        set formatoptions+=m
        " 合并两行中文时，不在中间加空格
        set formatoptions+=B
    " }

    " other 其他设置 {
        " vimrc 文件修改后自动加载 windows && linux
        autocmd! bufwritepost _vimrc source %
        autocmd! bufwritepost .vimrc source %

        " 自动补全配置
        " 让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
        set completeopt=longest,menu

        " 允许在有未保存的修改时切换缓冲区，此时的修改由 vim 负责保存  
        set hidden
        " 命令补全模式
        " “” 只用第一个匹配补全。
        " “full” 用下一个完整的匹配补全。在最后一次匹配之后，使用原来的字符串，然后又是第一个匹配
        " “longest” 用最长的公共子串补全。如果结果没有变长，使用下一个部分
        " “longest:full” 类似于 “longest”，但如果 ‘wildmenu’ 打开的话，使用之
        " “list” 如果有多于一个补全，列出所有的匹配
        " “list:full” 如果有多于一个补全，列出所有的匹配并先用第一个补全
        " “list:longest” 如果有多于一个补全，列出所有的匹配并先用最长的子串补全
        set wildmode=list:longest
        " 开启此功能.
        " 更多的字符被发送到屏幕,提高重绘的平滑度等...就是屏幕显示更流畅
        set ttyfast

        " 使用十进制来增加数字
        " 比如你的光标在一个数字上时,输入数字 10 并按下 <C-a>,那么这个数字会加10
        set nrformats=
        " 增强模式中的命令行自动完成操作
        set wildmenu
        " 忽略这些文件增强功能 ??????
        set wildignore+=*.aux,*.out,*.toc " LaTeX intermediate files  
        set wildignore+=*.jpg,*.bmp,*.gif " binary images  
        set wildignore+=*.luac " Lua byte code  
        set wildignore+=*.o,*.obj,*.exe,*.dll,*.manifest " compiled object files  
        set wildignore+=*.pyc " Python byte code
        set wildignore+=*.spl " compiled spelling word lists  
        set wildignore+=*.sw? " Vim swap files

        " 回车即选中当前项
        inoremap <expr> <CR>       pumvisible() ? "\<c-y>" : "\<cr>"

        " 打开自动定位到最后编辑的位置, 需要确认 .viminfo 当前用户可写
        if has("autocmd")
          au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
        endif
    " }
" }

" UI 用户界面展示设置 {
    " 开启语法高亮
    syntax on

    " 显示行号
    set number
    " 取消换行
    set nowrap

    " 突出显示当前列
    " set cursorcolumn
    " 突出显示当前行
    set cursorline
    " 突出行的颜色在选择了主题的情况下设置无效
    hi CursorLine guibg=white ctermbg=white

    " 退出 vim 后,vim 的内容仍显示在屏幕上
    set t_ti= t_te=

    " 显示当前行号
    set ruler

    " 状态栏显示正在输入的命令
    "set showcmd
    " 左下角显示当前 vim 模式
    set showmode

    " 显示状态栏 如果你又 powerline 状态栏插件的话,设置 2 为总是显示
    set laststatus=2

    " 光标的上下方至少保留显示的行数
    set scrolloff=10

    " 高亮显示括号匹配
    set showmatch

    " 高亮搜索文字
    set hlsearch
    " 搜索所见即所得
    set incsearch
    " 搜索忽略大小写
    set ignorecase
    " 一个以上大写字母时仍大小写敏感
    set smartcase

    " 缩进配置
    set smartindent
    " 自动缩进
    set autoindent

    " tab 键宽度为4空格
    set tabstop=4
    " 每一次缩进对应的空格数
    set shiftwidth=4
    " 按退格键可以一次删掉4个空格
    set softtabstop=4
    set smarttab
    " 将 tab 自动转化成空格
    set expandtab
    " 缩进时,取整
    set shiftround

    " 代码折叠
    set foldenable
    " 折叠方法
    " manual    手工折叠
    " indent    使用缩进表示折叠
    " expr      使用表达式定义折叠
    " syntax    使用语法定义折叠
    " diff      对没有更改的文本进行折叠
    " marker    使用标记进行折叠, 默认标记是 {{{ 和 }}}
    set foldmethod=indent
    set foldlevel=99
    " 代码折叠自定义快捷键 <leader>zz
    let g:FoldMethod = 0
    map <leader>zz :call ToggleFold()<cr>
    fun! ToggleFold()
        if g:FoldMethod == 0
            exe "normal! zM"
            let g:FoldMethod = 1
        else
            exe "normal! zR"
            let g:FoldMethod = 0
        endif
    endfun

    " 相对行号
    set relativenumber number
    autocmd FocusLost * :set norelativenumber number
    autocmd FocusGained * :set relativenumber
    " 插入模式下用绝对行号,普通模式下用相对
    autocmd InsertEnter * :set norelativenumber number
    autocmd InsertLeave * :set relativenumber
    function! NumberToggle()
      if(&relativenumber == 1)
        set norelativenumber number
      else
        set relativenumber
      endif
    endfunc
    nnoremap <C-n> :call NumberToggle()<cr>

    " 设置主题,配色方案
    set background=dark " dark | light
    set t_Co=256
    " 配色素雅
    "colorscheme solarized
    " 配色明亮,欢快
    colorscheme molokai

    " 设置光标 leslieyuan start
    let &t_SI.="\e[5 q" "SI = INSERT mode
    "let &t_SR.="\e[4 q" "SR = REPLACE mode
    let &t_EI.="\e[1 q" "EI = NORMAL mode (ELSE)

    "Cursor settings:

    "  1 -> blinking block
    "  2 -> solid block
    "  3 -> blinking underscore
    "  4 -> solid underscore
    "  5 -> blinking vertical bar
    "  6 -> solid vertical bar

    "let &t_SI = "\<Esc>]50;CursorShape=1\x7"
    "let &t_SR = "\<Esc>]50;CursorShape=2\x7"
    "let &t_EI = "\<Esc>]50;CursorShape=0\x7"
    " 设置光标 leslieyuan end
" }

" Key (re)Mappings 键位绑定 {
    " 关闭方向键, 只允许使用 hjkl
    map <Left> <Nop>
    map <Right> <Nop>
    map <Up> <Nop>
    map <Down> <Nop>

    " F1 - F6 设置
    " F1 废弃这个键 防止调出系统帮助
    noremap <F1> <Esc>"
    " F2 行号开关，用于鼠标复制代码用
    " 为方便复制，用<F2>开启/关闭行号显示:
    function! HideNumber()
      if(&relativenumber == &number)
        set relativenumber! number!
      elseif(&number)
        set number!
      else
        set relativenumber!
      endif
      set number?
    endfunc
    nnoremap <F2> :call HideNumber()<CR>
    " F3 显示可打印字符开关
    nnoremap <F3> :set list! list?<CR>
    " F4 换行开关
    nnoremap <F4> :set wrap! wrap?<CR>
    " F6 语法开关，关闭语法可以加快大文件的展示
    nnoremap <F6> :exec exists('syntax_on') ? 'syn off' : 'syn on'<CR>

    " 在插入模式下按 <F5> 进入粘贴模式,这时候粘贴复制过来的代码不会触发自动缩进
    set pastetoggle=<F5>
    " 离开插入模式时,关闭粘贴模式
    autocmd InsertLeave * set nopaste
    " 在插入模式使用粘贴会自动开启粘贴模式,不需要手动设置
    function! XTermPasteBegin()
      set pastetoggle=<Esc>[201~
      set paste
      return ""
    endfunction
    inoremap <special> <expr> <Esc>[200~ XTermPasteBegin()

    " 分屏窗口移动
    map <C-j> <C-W>j
    map <C-k> <C-W>k
    map <C-h> <C-W>h
    map <C-l> <C-W>l

    " 空格键进入搜索模式
    map <space> /
    " 搜索模式为默认更先进的正则规则 见帮助 :h magic
    nnoremap / /\v
    vnoremap / /\v
    " 去掉搜索高亮
    noremap <silent><leader>/ :nohls<CR>
    " # 正向搜索光标下单词,* 反向搜索光标下单词
    nnoremap # *
    nnoremap * #

    " http://stackoverflow.com/questions/13194428/is-better-way-to-zoom-windows-in-vim-than-zoomwin
    " Zoom / Restore window.
    function! s:ZoomToggle() abort
        if exists('t:zoomed') && t:zoomed
            execute t:zoom_winrestcmd
            let t:zoomed = 0
        else
            let t:zoom_winrestcmd = winrestcmd()
            resize
            vertical resize
            let t:zoomed = 1
        endif
    endfunction
    command! ZoomToggle call s:ZoomToggle()
    nnoremap <silent> <Leader>z :ZoomToggle<CR>

    " 绑定键
    noremap H ^
    noremap L $

    " 按键;和:一样的效果,进入命令行 
    nnoremap ; :

    " tab(选项卡) 操作
    " http://vim.wikia.com/wiki/Alternative_tab_navigation
    " http://stackoverflow.com/questions/2005214/switching-to-a-particular-tab-in-vim

    " tab切换
    map <leader>th :tabfirst<cr>
    map <leader>tl :tablast<cr>
    map <leader>tn :tabnext<cr>
    map <leader>tp :tabprev<cr>
    map <leader>te :tabedit<cr>
    map <leader>td :tabclose<cr>
    map <leader>tm :tabm<cr>

    " normal模式下切换到确切的tab
    noremap <leader>1 1gt
    noremap <leader>2 2gt
    noremap <leader>3 3gt
    noremap <leader>4 4gt
    noremap <leader>5 5gt
    noremap <leader>6 6gt
    noremap <leader>7 7gt
    noremap <leader>8 8gt
    noremap <leader>9 9gt
    noremap <leader>0 :tablast<cr>

    " 在两个tab间切换,当前的总是第一个 
    let g:last_active_tab = 1
    " nnoremap <leader>gt :execute 'tabnext ' . g:last_active_tab<cr>
    " nnoremap <silent> <c-o> :execute 'tabnext ' . g:last_active_tab<cr>
    " vnoremap <silent> <c-o> :execute 'tabnext ' . g:last_active_tab<cr>
    nnoremap <silent> <leader>tt :execute 'tabnext ' . g:last_active_tab<cr>
    autocmd TabLeave * let g:last_active_tab = tabpagenr()

    " 新建tab  Ctrl+t
    nnoremap <C-t>     :tabnew<CR>
    inoremap <C-t>     <Esc>:tabnew<CR>

    " 比如普通模式中,Y 直接赋值到行尾
    map Y y$

    " 复制选中区到系统剪切板中
    vnoremap <leader>y "+y

    " select all 选择所有
    map <Leader>sa ggVG"

    " select block 选择区域块
    nnoremap <leader>v V`}

    " 滚动屏幕为2行
    nnoremap <C-e> 2<C-e>
    nnoremap <C-y> 2<C-y>

    " 退出当前编辑文件
    nnoremap <leader>q :q<CR>
    " 保存当前编辑文件
    nnoremap <leader>w :w<CR>
" }
```