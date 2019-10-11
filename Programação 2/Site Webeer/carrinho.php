<?php
include "includes/cabecalho.php";
?>

	<div class="container">
		<section class="col-1">
			
		</section>
		<section class="col-2">	
			<?php
			include "includes/functions.php";
			if(!isset($_SESSION['carrinho'])){
				echo "<h2>Seu carrinho está vazio!";
			}
			else {
				?>
					<h2>Meu carrinho</h2>
					<div class="itemCarrinho">
						<span class="produtoCarrinho"><strong>Produto</strong></span>
						<span class="qtdeCarrinho"><strong>Quantidade</strong></span>
						<span class="precoCarrinho"><strong>Valor</strong></span>

					</div>
				<?php
					$total = 0;
					foreach($_SESSION['carrinho'] as $id => $item){
							include "includes/conexao.php";						
							$sql = "select imagem from produto  where produto.id = $id";				
							$resultado = mysqli_query($conexao, $sql);
							$produto = mysqli_fetch_array($resultado);
						?>
						<div class="itemCarrinho">
							<img src="imagens/produtos/<?=mostraImagem($produto['imagem']);?>" alt="<?=$produto['nome'];?>" width="60" height=”40”>
							<span class="produtoCarrinho"><?=$item['nome'];?></span>
							<input type="number" min="1" value="<?=$item['quantidade'];?>" style="width: 5em;" onchange="atualizaQuantidade(<?=$id;?>, this.value, <?=$item['valorFinal'];?>)">
							
							<span class="precoUnit" id="preco<?=$id;?>"><?=formataPreco(($item['valorFinal'])*($item['quantidade']));?></span>
							<span class="excluirCarrinho"><a href="excluiProd.php?id=<?=$id;?>" title="excluir item">X</a></span>
						</div>							
						<?php
						$total += ($item['quantidade'] * $item['valorFinal']);
					}
					?>
					<div class="itemCarrinho total">
						<span>Total:</span>
						<span class="precoCarrinho"><strong id="precoTotal"><?=formataPreco($total);?></strong></span>
					</div>
					<div class="botoes">
						<a href="index.php"><button>Continuar comprando</button></a>
						<a href="fecharPedido.php"><button>Finalizar pedido</button></a>
					</div>
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

