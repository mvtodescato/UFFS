<?php
include "includes/cabecalho.php";
?>
	<body>
	<div class="container">
		
		<section class="col-1">
			
			<img src="imagens/lateral.jpg" alt="miniatura1" width="300px" height="700px" >
			
		</section>




		<section class="col-2">
			<?php
			if(isset($_GET['secao'])){
				$categoriaSelecionada = $_GET['secao'];
				$titulo = $CATEGORIAS[$categoriaSelecionada];
			}
			elseif(isset($_GET['busca'])){
				$titulo = "Resultado da busca por \"{$_GET['busca']}\" ";
			}
			elseif(isset($_GET['ofertas'])){
				$titulo = "Ofertas";
			}
			else{
				$titulo = "Novidades";
			}
			?>
			<h2><?=$titulo;?></h2>

		
			<div class="lista-produtos">
				
				<?php
				include "includes/conexao.php";
				include "includes/functions.php";
				$sql = "select id, nome, imagem, valor, desconto from produto";
				if(isset($categoriaSelecionada))
					$sql.= " where $categoriaSelecionada IS TRUE";
				elseif(isset($_GET['busca']))
					$sql.=" where nome like '%{$_GET['busca']}%'";
				elseif(isset($_GET['ofertas']))
					$sql.= " where oferta IS TRUE";
				else
					$sql.= " order by id desc limit 10";

				$resultado = mysqli_query($conexao, $sql);
				if(mysqli_num_rows($resultado) == 0){
					echo "<p>Nenhum produto encontrado</p>";
				}
				else{
					while ($produto = mysqli_fetch_array($resultado)){
					
				

				?>
                     <div class="produto">                      
                        <figure>
                            <a href="produto.php?id=<?=$produto['id'];?>">
                            <img src="imagens/produtos/<?=mostraImagem($produto['imagem']);?>" alt="<?=$produto['nome'];?>">
                            <figcaption><?=$produto['nome'];?>
                                <span class="preco"> <?=mostraPreco($produto['valor'], $produto['desconto']);?>  </span>
                            </figcaption>
                            </a>
                                  <?php 
                            if(@array_key_exists($produto['id'], $_SESSION['carrinho'])){    ?>
                                <div class="noCarrinho" id="<?=$produto['id'];?>">no carrinho!</div>
                            <?php 
                            }    ?>
                           </figure>
                       </div>
                      <?php
                   }
               }
               ?>
            </div> 					
		</section>
		<section class="col-3">
			<img src="imagens/lateral2.jpg" alt="miniatura1" width="300px" height="700px" >
			
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