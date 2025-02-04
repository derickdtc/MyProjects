//let display = document.getElementById('display').value
function calcular(tipo , elemento) {

	if (tipo==='acao') {
	if (elemento==='c'){
		document.getElementById('display').value==' '
	}
	if (elemento=='+'||elemento=='*'||elemento=='/'||elemento=='-'||elemento=='.') {
		document.getElementById('display').value += elemento

	}
	if (elemento==='=') {
		var resultado_campo = document.getElementById('display').value
		var resultado = eval(resultado_campo)
		document.getElementById('display').value= resultado 
	}

	} else {
    document.getElementById('display').value += elemento

	}
	

}