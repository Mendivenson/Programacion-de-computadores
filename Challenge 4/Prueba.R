list = c(' ','#')
ancho = cli::console_width()
for (i in 1:ancho){
  cat(rep_len(list, ancho), sep = '',end = '\n')
  list = rev(list)
}
