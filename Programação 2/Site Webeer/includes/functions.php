<?php
function mostraImagem($nomeArquivo){
	if($nomeArquivo == '')
		return "default.jpg";
	else
		return $nomeArquivo;
}


function mostraPreco($valor, $desconto){
	if($desconto == 0){
		return "<span class='precoFinal'>R$ ".str_replace(".", ",", number_format($valor, 2))."</span>";
	}
	else{
		return "De R$ <del>".str_replace(".", ",", number_format($valor, 2))."</del> por 
		<span class='precoFinal'>R$ ".str_replace(".", ",", number_format(($valor - $desconto), 2))."</span>";
	}
}

function formataPreco($valor){
	return "R$ ". str_replace(".", ",", number_format($valor, 2));
}
?>