<?php
include "includes/cabecalho.php";
?>

	<div class="container">
		<section class="col-1">
			
		</section>
		<section class="col-2">	
		<?php
				include "includes/conexao.php";
				include "includes/functions.php";
				
				if(!is_numeric($_GET['id'])){
					echo "<h2>Identificador de produto inválido</h2>";
				}
				else {
					$id = $_GET['id'];								
					$sql = "select nome, id, imagem, valor, desconto, descricao, catPilsen,catVienna,catWeiss,catAmericanIPA, catOutros from produto  where produto.id = $id";				
					$resultado = mysqli_query($conexao, $sql);
					$produto = mysqli_fetch_array($resultado);									
					if(mysqli_num_rows($resultado) == 0){
						echo "<h2>Produto não encontrado</h2>";
					}
				}				
					?>

			<div class="detalhes-produto">
				<h2><?=$produto['nome'];?></h2>
				<figure class="imag">
				<img src="imagens/produtos/<?=mostraImagem($produto['imagem']);?>" alt="<?=$produto['nome'];?>">
				</figure>
			
				<div class="form">					
					<p>
						<span class="preco">
						<?=mostraPreco($produto['valor'],$produto['desconto']);?>	
						</span>
					</p>	
				
					<form action="adiciona.php" method="post" id="add-carrinho">
						<label for="quantidade">Quantidade:</label>
						<input type="number" name="quantidade" value="1" min="1">
						<input type="hidden" name="id" value="<?=$produto['id']?>">
						<input type="hidden" name="nome" value="<?=$produto['nome']?>">
						<input type="hidden" name="valorFinal" value="<?=($produto['valor'] - $produto['desconto'])?>">
						<br><br>
						<input type="submit" value="Adicionar ao Carrinho" name="adicionar">
						<br><br>
					</form>
					</div>
					<div class="detalhes">
						<hr>
					<h4>Detalhes do produto:</h4>								<p class= "desc">Descricao:   <?=nl2br($produto['descricao'])?></p>				
					
					<p class="detalhes">Categorias: <span class="cat-names">&nbsp;
					<?php
						$categorias = array();
						if($produto['catPilsen']==1){
							array_push($categorias, "Pilsen");							
						}
						if($produto['catVienna']==1){
							array_push($categorias, "Vienna");							
						}
						if($produto['catWeiss']==1){
							array_push($categorias, "Weiss");							
						}
						if($produto['catAmericanIPA']==1){
							array_push($categorias, "American IPA");							
						}					
						if($produto['catOutros']==1){
							array_push($categorias, "Outros");							
						}
																		
						foreach ($categorias as $lista){
							echo "$lista  ";
						}						
										
					?>
					</span></p>

				</div>	
				</div>									
		</section>
		</div>

	
	<footer><p>Webeer - Chapecó/SC</p>
		<ul class="social">
			<li><a href="https://www.facebook.com/webeer/"><img src="imagens/facebook.png" width="28" alt="Facebook"></a></li>
			<li><a href="https://twitter.com/webeer1"><img src="imagens/twitter.png" width="28" alt="Twitter"></a></li>
			<li><a href="http://instagram.com"><img src="imagens/instagram.png" width="29" alt="Instagram"></a></li>
		</ul>
	</footer>
	
	<script src="js/functions.js"></script>
</body>
</html>