
document.getElementById("fechar").onclick = function(){	
	document.getElementById("ajuda").style.display = 'none';
};


function formataPreco(valor){
	valor = parseFloat(valor);
	return valor.toLocaleString('pt-br',{style: 'currency', currency: 'BRL'});
}
function atualizaQuantidade(idProduto, quantidade, valorFinal) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("preco"+idProduto).innerHTML = formataPreco(parseInt(quantidade) * parseFloat(valorFinal)); 
            document.getElementById("precoTotal").innerHTML = formataPreco(this.responseText); 
        }
    };
    xhttp.open("GET", "ajax/atualizaValores.php?id="+idProduto+"&quantidade="+quantidade, true);
    xhttp.send();
}
