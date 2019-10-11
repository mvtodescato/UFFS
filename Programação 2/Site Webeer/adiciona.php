<?php
session_start();
if(array_key_exists($_POST['id'], $_SESSION['carrinho'])){ 
	$_SESSION['carrinho'][$_POST['id']]['quantidade'] += $_POST['quantidade'];
}
else{ 
	$_SESSION['carrinho'][$_POST['id']] = array("nome" => $_POST['nome'],
												"quantidade" => $_POST['quantidade'],
												"valorFinal" => $_POST['valorFinal']);
}
header("Location: carrinho.php");											
?>