class Despesa {
    constructor(ano, mes ,dia,tipo,descricao,valor){
        this.ano = ano
        this.mes = mes
        this.dia = dia
        this.tipo = tipo
        this.descricao = descricao
        this.valor = valor
    }
    validarDados(){
        for (let i in this) {
            if (this[i] == undefined || this[i] == null || this[i] == "") {
                return false
            }
            return true
        }
    }
}

class Bd{
    constructor(){
        let id = localStorage.getItem('id')
        if (id == null) {
            localStorage.setItem('id', 0)
        }
    }
    getProximoId(){
        let proximoId= localStorage.getItem('id')
        return (parseInt(proximoId) + 1)
    }

    gravar(d){
        let id = this.getProximoId()
        localStorage.setItem(id , JSON.stringify(d))
        localStorage.setItem('id', id)

    }

    recuperarTodosRegistros(){
        //array de despesas
        let despesas = Array() 

        let id = localStorage.getItem('id')
        for (let i = 1; i <= id; i++) {
            // recuperando a despesa
            let despesa = JSON.parse(localStorage.getItem(i))
            if (despesa == null) {
                continue
            }
            despesa.id = i
            despesas.push(despesa)
            
        }
        return despesas
    }

    pesquisar(despesa){
         let despesasFiltradas = Array()
         despesasFiltradas = this.recuperarTodosRegistros()
        console.log(despesasFiltradas)

        //Aplicando os filtros
        if (despesa.ano != '') {
            console.log('filtro de ano')
            despesasFiltradas = despesasFiltradas.filter(d => d.ano == despesa.ano)
        }
        if (despesa.mes != '') {
            console.log('filtro de mes')
            despesasFiltradas = despesasFiltradas.filter(d => d.mes == despesa.mes)
        }
        if (despesa.dia != '') {
            console.log('filtro de dia')
            despesasFiltradas = despesasFiltradas.filter(d => d.dia == despesa.dia)
        }
        if (despesa.tipo != '') {
            console.log('filtro de tipo')
            despesasFiltradas = despesasFiltradas.filter(d => d.tipo == despesa.tipo)
        }
        if (despesa.descricao != '') {
            console.log('filtro de descrição')
            despesasFiltradas = despesasFiltradas.filter(d => d.descricao == despesa.descricao)
        }
        if (despesa.valor != '') {
            console.log('filtro de valor')
            despesasFiltradas = despesasFiltradas.filter(d => d.valor == despesa.valor)
        }
        console.log(despesasFiltradas)
        return despesasFiltradas
    }

    remover(id){
        localStorage.removeItem(id)
    }

}
let bd = new Bd()

function cadastrarDespesa() {
    let ano = document.getElementById('ano')
    let mes = document.getElementById('mes')
    let  dia = document.getElementById('dia')
    let tipo = document.getElementById('tipo')
    let descricao = document.getElementById('descricao')
    let valor = document.getElementById('valor')

    let despesa = new Despesa(
        ano.value, mes.value, dia.value, tipo.value, descricao.value , valor.value
    )
    if (despesa.validarDados()) {

        bd.gravar(despesa)
        document.getElementById('modal_titulo').innerHTML ='Registro informado com sucesso'
        document.getElementById('modal_titulo_div').className = 'text-success'
        document.getElementById('modal_conteudo').innerHTML = 'Despesa foi cadastrado com sucesso'
        document.getElementById('modal_botao').innerHTML= 'Voltar'        

        // Primeiro, selecione o modal pelo ID
        let modalElement = document.getElementById('modalRegistrarDespesa');

        // Em seguida, crie uma instância do modal usando o Bootstrap 5
        let modalInstance = new bootstrap.Modal(modalElement);

        // Finalmente, mostre o modal
        modalInstance.show();
        //Limpando o formulário na index
        ano.value = ''
        mes.value = ''
        dia.value = ''
        valor.value = ''
        descricao.value = ''
        tipo.value = ''


    } else {
        console.log("Os dados são inválidos")
        document.getElementById('modal_titulo').innerHTML ='Erro ao inserir registro'
        document.getElementById('modal_titulo_div').className = 'text-danger'
        document.getElementById('modal_conteudo').innerHTML = 'Erro na gravação, verifique se os campos foram preenchidos corretamente'
        document.getElementById('modal_botao').innerHTML= 'Voltar e corrigir'
        // Primeiro, selecione o modal pelo ID
        let modalElement = document.getElementById('modalRegistrarDespesa');

        // Em seguida, crie uma instância do modal usando o Bootstrap 5
        let modalInstance = new bootstrap.Modal(modalElement);

        // Finalmente, mostre o modal
        modalInstance.show();
    }

}

function carregarListaDespesas(despesas = Array(), filtro = false) {
    
    if (despesas.length == 0 && filtro == false) {
        despesas = bd.recuperarTodosRegistros()

    }
    //Selecionando o elemento tbody da tabela

    let listaDespesas = document.getElementById('listaDespesas')
    listaDespesas.innerHTML = ''
    //Percorrer o array despesas listando cada despesa de forma dinâmica
    despesas.forEach(function(d){
        //console.log(d)
        //criando a linha
        let linha = listaDespesas.insertRow()
        //criando colunas
        linha.insertCell(0).innerHTML = `${d.dia}/${d.mes}/${d.ano}` 
        linha.insertCell(1).innerHTML = d.tipo 
        linha.insertCell(2).innerHTML = d.descricao 
        linha.insertCell(3).innerHTML = d.valor 
        //criando botão de exclusão
        let btn = document.createElement('button')
        btn.className= 'btn btn-danger '
        btn.innerHTML ='<i class="fas fa-times"></i> '
        btn.id = 'id_despesa_'+ d.id
        btn.onclick = function () {
            let id = this.id.replace('id_despesa_', '')
            //alert(id)
            bd.remover(id)
            window.location.reload()
        }
        linha.insertCell(4).append(btn)
         console.log(d)

    })
}

function pesquisarDespesa() {
    let dia = document.getElementById('dia').value
    let mes = document.getElementById('mes').value
    let ano = document.getElementById('ano').value
    let tipo = document.getElementById('tipo').value
    let descricao = document.getElementById('descricao').value
    let valor = document.getElementById('valor').value

    let despesa = new Despesa(ano, mes ,dia,tipo,descricao,valor)
    let despesas =  bd.pesquisar(despesa)

    carregarListaDespesas(despesas , true)
    
}
  







