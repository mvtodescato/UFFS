
<?php
include "includes/cabecalho.php";
?>
<?php
			if(!isset($_SESSION['login'])){			
				header("Location: login.php");
			}
			else {
				include "includes/conexao.php";
				include "includes/functions.php";
				$id = $_SESSION['id'];								
				$sql = "select nome, email,telef,cpf from cliente where id = $id";				
					$resultado = mysqli_query($conexao, $sql);
					$cliente = mysqli_fetch_array($resultado);
					if($resultado){
						$sql = "select rua, bairro,uf,cidade,numero,complemento,CEP from ender where idCliente = $id";				
						$resultado = mysqli_query($conexao, $sql);
						$ender = mysqli_fetch_array($resultado);
					}
				?>

	<div class="container">
		<section class="col-1">
			
		</section>
		<section class="col-2">
			
			
				<h2>Dados Pessoais</h2>
				<div class="form">
					<p>
						<span class="dados"><strong>NOME:</strong> <?=$cliente['nome']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>EMAIL:</strong> <?=$cliente['email']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>TELEFONE:</strong> <?=$cliente['telef']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>CPF:</strong> <?=$cliente['cpf']?></span>
					</p>
				</div>
				<h2>Meu endereço</h2>
				<div class="form">
					<p>
						<span class="dados"><strong>RUA:</strong> <?=$ender['rua']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>NUMERO:</strong> <?=$ender['numero']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>BAIRRO:</strong> <?=$ender['bairro']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>COMPLEMENTO:</strong> <?=$ender['complemento']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>CEP:</strong> <?=$ender['CEP']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>CIDADE:</strong> <?=$ender['cidade']?></span>
					</p>
				</div>
				<div class="form">
					<p>
						<span class="dados"><strong>ESTADO:</strong> <?=$ender['uf']?></span>
					</p>
				</div>
				<h2>MEUS PEDIDOS</h2>
				<?php
					$sql = "select count(*) as quant from pedido where idCliente = $id";				
					$resultado = mysqli_query($conexao, $sql);
					$quant = mysqli_fetch_array($resultado)[0];
					if($quant == 0){
						echo "<span>Você não fez nenhum pedido ainda!</span>";
					}
					else{
						$num = -1;
						for($i=0;$i<$quant;$i++){
							$sql = "select numero,taxaEntrega,dataPedido,dataEntrega,status,precoT from pedido where (idCliente = $id AND numero>$num)  order by numero asc limit 1";
							$resultado = mysqli_query($conexao, $sql);
							$pedido = mysqli_fetch_array($resultado);
							$num = $pedido['numero'];
						?>
						<div class="pedidos">
							<span class="numeroPedido"><strong>CÓDIGO DO PEDIDO:&nbsp&nbsp</strong><?=$pedido['numero']?></span>
							<br>
							<br>
							<span class="taxaEntrega">Taxa entrega:&nbsp&nbsp<?=formataPreco(($pedido['taxaEntrega']))?></span>
							<br>
							<br>
							<span class="dataPedido">Data do pedido: &nbsp&nbsp<?=$pedido['dataPedido']?></span>
							<br>
							<br>
							<span class="dataEntrega">Data esperada da Entrega:&nbsp&nbsp<?=$pedido['dataEntrega']?></span>
							<br>
							<br>
							<span class="precoT"><strong>Preço Total:&nbsp&nbsp</strong> <?=formataPreco(($pedido['precoT']))?></span>
							<br>
							<br>
							<?php
								if($pedido['status'] == 0){
									echo "<span><strong>PEDIDO CANCELADO!</strong></span>";
								}else if($pedido['status'] == 1){
									echo "<span><strong>PEDIDO EM ANDAMENTO!</strong></span>";
								}else{
									echo "<span><strong>PEDIDO FINALIZADO E ENTREGUE!</strong></span>";
								}
							?>
						</div>
						<br>

						<?php
						}
					}
				?>



		<?php
	}
	?>
		</section>
<footer><p>Webeer - Chapecó/SC</p>
		<ul class="social">
			<li><a href="https://www.facebook.com/webeer/"><img src="imagens/facebook.png" width="28" alt="Facebook"></a></li>
			<li><a href="https://twitter.com/webeer1"><img src="imagens/twitter.png" width="28" alt="Twitter"></a></li>
			<li><a href="http://instagram.com"><img src="imagens/instagram.png" width="29" alt="Instagram"></a></li>
		</ul>
	</footer>
	<script src="js/functions.js"></script>