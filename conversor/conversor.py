input_string = "caracteres a enviar"#caracter o caracteres a enviar

data = (''.join(format(ord(x), 'b') for x in input_string))#convertira nuestro datos a binarios
print (data)#imprime los caracteres en binarios
