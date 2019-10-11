<?php
session_start();
if(!isset($_SESSION['login'])){			
	header("Location: login.php");
}

include "includes/conexao.php";
if(isset($_POST['finalizar'])){
	$valortotal =  $_POST['total'];
	$valorEntrega = 10;
	$dataPedido = date('Y-m-d');
	$dataEntrega = date('Y-m-d', strtotime('+2 week'));
	$sql = "insert into pedido (idCliente, taxaEntrega, dataPedido,dataEntrega, status, precoT,tipopagamento) values 
			({$_SESSION['id']}, $valorEntrega, '$dataPedido','$dataEntrega', 1,$valortotal,1)";
	$resultado = mysqli_query($conexao, $sql);
	if($resultado){
		$sql = "select numero from pedido where idCliente = {$_SESSION['id']} order by numero desc limit 1";
		$resultado = mysqli_query($conexao, $sql);
		$numPedido = mysqli_fetch_array($resultado)[0];
		foreach ($_SESSION['carrinho'] as $idProduto => $item){
			$sql = "insert into pedido_itens (numPedido, idProduto, quantidade, valorT) values 
					($numPedido, $idProduto, {$item['quantidade']}, {$item['valorFinal']})";
			$resultado = mysqli_query($conexao, $sql);
		}
		$mensagem = "Seu pedido foi finalizado com sucesso. Acompanhe o status através da opção Minha Conta.";
		unset($_SESSION['carrinho']);
	}
	else {
		$mensagem = "Erro ao gravar o pedido";
	}
}
include "includes/cabecalho.php";
?>

	<div class="container">
		<section class="col-2">
		<?php
		if(!isset($_POST['finalizar']) && !isset($_SESSION['carrinho'])){
			echo "<h2>Seu carrinho está vazio!</h2>";
		}
		else{
		?>
			<h2>Fechar pedido</h2>
			<?php
			if(!isset($_POST['finalizar'])){ 
			?>
			<hr>
			<p><strong>Escolha o tipo de entrega:</strong></p>
			<form method="post">
				<div class="form-item">
				 <label><input type="radio" name="taxa" value="10" id="retirar" checked onclick="taxaEntrega(this.value)">Entrega tradicional: R$10,00 (10 a 17 dias)</label><br>
				</div>
				<hr>
				<?php
				include "includes/functions.php";
				echo "<p><strong>Confira seus produtos:</strong></p>";
				echo "<div class='itemCarrinho'>
						<span class='produtoCarrinho'><strong>Produto</strong></span>
						<span class='qtdeCarrinho'><strong>Quantidade</strong></span>
						<span class='precoCarrinho'><strong>Total do item</strong></span>
					</div>";
				$total = 0;
				foreach($_SESSION['carrinho'] as $idProduto => $item){
				?>
					<div class="itemCarrinho" id="<?=$idProduto?>">
						<span class="produtoCarrinho"><?=$item['nome'];?></span>
						<span class="qtdeCarrinho"><?=$item['quantidade'];?></span>
						<span class="precoCarrinho"><?=formataPreco($item['quantidade'] * $item['valorFinal']);?></span>
					</div>
					<?php
					$total += $item['quantidade'] * $item['valorFinal'];
				}
				
				?>
				<div class="itemCarrinho total">
					<span>Total em produtos:</span>
					<span class="precoCarrinho"><strong><?=formataPreco($total);?></strong></span>
					<input type="hidden" name="totalProdutos" id="totalProdutos" value="<?=$total;?>">
				</div>
				<?php
				$total += 10;
				?>
				<div class="itemCarrinho total">
					<span>Taxa de Entrega:</span>
					<span class="precoCarrinho" id="taxaExibida"><strong><?=formataPreco(10);?></strong></span>					
				</div>
				<div class="itemCarrinho total">
					<span>TOTAL DO PEDIDO:</span>
					<span class="precoCarrinho" id="totalExibido"><strong><?=formataPreco($total);?></strong></span>
					<input type="hidden" name="total" value="<?=$total;?>"/>	
				</div>
				<div class="botoes">
				<a href="carrinho.php"><button type="button">Voltar para o carrinho</button></a>
				<button type="submit" name="finalizar">Finalizar pedido</button>
				</div>
				</form>
				<?php
				}
				else{ 
					echo $mensagem;
				}
		}
		?>
		</section>
	</div>

