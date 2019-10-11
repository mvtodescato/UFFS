<?php
	session_start();
	unset($_SESSION['carrinho'][$_GET['id']]);
	if(count($_SESSION['carrinho']) == 0)
		unset($_SESSION['carrinho']);
	header("Location: carrinho.php");
?>