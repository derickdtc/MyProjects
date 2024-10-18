
var altura;
var largura;
var vidas =1;
var tempo=61;
var tempoMosca;


var nivelExtraido = (window.location.search).replace('?', '')



if (nivelExtraido === "normal") {
	tempoMosca= 1500
} else if(nivelExtraido === "dificil") {
	tempoMosca = 1000
}else {
	tempoMosca = 750
}

alert(tempoMosca)
alert(nivelExtraido)
function ajustarTamanhoPalcoJogo() {
	altura = window.innerHeight
	largura= window.innerWidth
	console.log(altura , largura)
}

var cronometro = setInterval(() => {
	tempo--
	if (tempo < 0) {
		clearInterval(cronometro)
		window.location.href= 'vitoria.html'
	}
	document.getElementById('cronometro').innerHTML= tempo

}, 1000);
function posicaoRandomica() {	


	if (document.getElementById('mosca')) {
		document.getElementById('mosca').remove()
		if (vidas==3) {
			//alert("FIM DE JOGO")
			window.location.href = 'derrota.html'
		} else {
			document.getElementById('v'+ vidas).src = "imagens/coracao_vazio.png"
			vidas++
		}	
		
	} 

	var posicaoX = Math.round(Math.random() * largura) - 90
	var posicaoY = Math.round(Math.random() * altura)- 90 

	posicaoX = posicaoX < 0? 0 : posicaoX
	posicaoY = posicaoY < 0 ? 0 : posicaoY

	//criar elemento HTML
	var mosca = document.createElement('img')
	mosca.src = 'imagens/mosca.png'
	mosca.className = tamanhoAleatorio()+ ' '+ ladoAleatorio() 
	mosca.style.left = posicaoX + 'px'
	mosca.style.top = posicaoY + 'px'
	mosca.style.position = 'absolute'
	mosca.id = 'mosca'
	mosca.onclick= function () {		
		this.remove()
	}


	document.body.appendChild(mosca)	
}

function tamanhoAleatorio() {
	var classe = Math.floor(Math.random() * 3)

	switch (classe) {
		case 0:
			return 'mosca1'	
		case 1:
			return 'mosca2'		
		case 2:
			return 'mosca3'			
	}

}

function ladoAleatorio() {
	var lado = Math.floor(Math.random() * 2)

	switch (lado) {
		case 0:
			return 'ladoA'
		case 1:
			return 'ladoB'
	}

}
setInterval(() => {
	posicaoRandomica()
}, tempoMosca);


















// Chamar funções 
ajustarTamanhoPalcoJogo()
//posicaoRandomica()