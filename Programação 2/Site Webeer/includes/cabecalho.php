<?php
@session_start();
?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta charset="utf-8">
	<title>Webeer</title>
	<link rel="icon" type="image/jpg" href="imagens/icone.ico" >
	<link rel="stylesheet" type="text/css" href="rent.css">
	<link rel="stylesheet" type="text/css" href="css/forms.css">
	<link rel="stylesheet" type="text/css" href="css/produto_carrinho.css">
	<link href="https://fonts.googleapis.com/css?family=Lobster" rel="
	stylesheet">
	<link href="https://fonts.googleapis.com/css?family=UnifrakturMaguntia" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css?family=Aref+Ruqaa" rel="stylesheet">
</head>
<body>

	<header>
	<h1><p class="titulo" href="index.html"><a href="index.php">Webeer</a></p></h1>

		<p class="carrinho"><a href="carrinho.php">Meu carrinho

		<?php 

		     if(isset($_SESSION['carrinho']))
		         echo "(".count($_SESSION['carrinho']).")";
		?>
		</span>
		<img src="imagens/cart.png" width="28" alt="Carrinho"></a></p>
		<p class="cadastro">
			<?php
			if(isset($_SESSION["login"]) && isset($_SESSION["nome"])){
				$_SESSION["login"];
				$variavel = "Olá, ";
				$variavel.= $_SESSION["nome"] ;
				$variavel.="! <a href=\"logoff.php\">(Sair)</a>";
			}else{
				$variavel = "<a href=\"login.php\">Faça Login</a><a> ou</a><a href=\"cad.php\"> Cadastre-se</a>";
			}
			 ?>
		<?=$variavel?> &nbsp;&nbsp;&nbsp;&nbsp;</p>
<section class="busca">
				<form action="index.php" >
					<input type="search" placeholder="Busca..." name="busca" 
					value="<?=isset($_GET['busca']) ? $_GET['busca'] : '';?>">
					
					<button>OK</button>
				</form>
			</section>


		<p id="exibeMenu">Menu</p>
		<nav class="menu-opcoes">    
			<ul>
				<li><a href="webeer.php">A Webeer</a></li>
				<li><a href="index.php">Categorias</a>
					<ul>
						<?php
						include "includes/categorias.php";
						foreach ($CATEGORIAS as $indice => $nomeCategoria){
							echo "<li><a href='index.php?secao=$indice'>$nomeCategoria</a></li>";
						}
						?>	
					</ul>
				</li>	
				<?php echo "<li><a href='index.php?ofertas=1'>Ofertas</a></li>";
				?>
				<li><a href="minhaConta.php">Minha Conta</a></li>
				<li><a href="contato.php">Contato</a></li>
				
			</ul>
		</nav>
	</header>
