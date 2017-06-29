autocmd bufnewfile *.cpp so my_header.txt
autocmd bufnewfile *.cpp exe "1," . 5 . "g/PROG:/s//PROG: " .expand("%:r")
autocmd bufnewfile *.cpp execute "normal G"

autocmd bufnewfile *.cpp execute "normal! i#include <iostream>"
autocmd bufnewfile *.cpp execute "normal! o#include <fstream>"
autocmd bufnewfile *.cpp execute "normal! o"
autocmd bufnewfile *.cpp execute "normal! ousing namespace::std;"
autocmd bufnewfile *.cpp execute "normal! o"
autocmd bufnewfile *.cpp execute "normal! oint main() {"
autocmd bufnewfile *.cpp execute "normal! oofstream fout(\"".expand("%:r").".out\");"
autocmd bufnewfile *.cpp execute "normal! oifstream fin(\"".expand("%:r").".in\");"
autocmd bufnewfile *.cpp execute "normal! oreturn 0;"
autocmd bufnewfile *.cpp execute "normal! o}"
