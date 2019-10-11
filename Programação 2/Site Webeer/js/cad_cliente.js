

document.getElementById("form-contato").onsubmit = validaCadastro;
function validaCadastro(){
	var contErro = 0;


	var nome = document.getElementById("nome");
	var erro_nome = document.getElementById("msg-nome");
	if((nome.value == "") || (nome.value == "") ){
		erro_nome.innerHTML = "Por favor digite o Nome completo";
		erro_nome.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_nome.style.display = "none";
	}


	var email = document.getElementById("email");
	var erro_email = document.getElementById("msg-email");
	if((email.value == "") || (email.value.indexOf("@") == -1)){
		erro_email.innerHTML = "Por favor digite o E-mail";
		erro_email.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_email.style.display = 'none';
	}

		var telefone = document.getElementById("telefone");
	var erro_telefone = document.getElementById("msg-telefone");
	if((telefone.value == "") || (telefone.value == "")){
		erro_telefone.innerHTML = "Por favor digite o Telefone";
		erro_telefone.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_telefone.style.display = 'none';
	}

		var cpf = document.getElementById("cpf");
	var erro_cpf = document.getElementById("msg-cpf");
	if((cpf.value == "") || (cpf.value == "") ){
		erro_cpf.innerHTML = "Por favor digite o CPF";
		erro_cpf.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_cpf.style.display = 'none';
	}

	var rua = document.getElementById("rua");
	var erro_rua = document.getElementById("msg-rua");
	if(rua.value == ""){
		erro_rua.innerHTML = "Por favor digite a Rua";
		erro_rua.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_rua.style.display = "none";
	}
	var nome = document.getElementById("cidade");
	var erro_nome = document.getElementById("msg-cidade");
	if((nome.value == "") || (nome.value == "") ){
		erro_nome.innerHTML = "Por favor digite o nome da sua Cidade";
		erro_nome.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_nome.style.display = "none";
	}

		var numero = document.getElementById("numero");
	var erro_numero = document.getElementById("msg-numero");
	if((numero.value == "") || (numero.value == "")){
		erro_numero.innerHTML = "Por favor digite o Número";
		erro_numero.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_numero.style.display = 'none';
	}

	var bairro = document.getElementById("bairro");
	var erro_bairro = document.getElementById("msg-bairro");
	if((bairro.value == "") || (bairro.value == "")){
		erro_bairro.innerHTML = "Por favor selecione o Bairro";
		erro_bairro.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_bairro.style.display = 'none';
	}	

		var estado = document.getElementById("estado");
	var erro_estado = document.getElementById("msg-estado");
	if((estado.value == "") || (estado.value == "")){
		erro_estado.innerHTML = "Por favor selecione o Estado";
		erro_estado.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_estado.style.display = 'none';
	}		

	var cep = document.getElementById("cep");
	var erro_cep = document.getElementById("msg-bairro2");
	if((cep.value == "") || (cep.value == "")){
		erro_cep.innerHTML = "Por favor digite o CEP";
		erro_cep.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_cep.style.display = 'none';
	}

	var login = document.getElementById("login");
	var erro_login = document.getElementById("msg-login");
	if(login.value == ""){
		erro_login.innerHTML = "Por favor digite o login";
		erro_login.style.display = 'block';
		contErro+=1;
	}
	else if (login.value.length < 6){
		erro_login.innerHTML = "O Login deve possuir pelo menos 6 caracteres";
		erro_login.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_login.style.display = 'none';
	}


	var senha = document.getElementById("senha");
	var erro_senha = document.getElementById("msg-senha");
	if(senha.value == ""){
		erro_senha.innerHTML = "Por favor digite a Senha";
		erro_senha.style.display = 'block';
		contErro+=1;
	}
	else if (senha.value.length < 6){
		erro_senha.innerHTML = "A Senha deve possuir pelo menos 6 caracteres";
		erro_senha.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_senha.style.display = 'none';
	}


	var senha2 = document.getElementById("senha2");
	var erro_senha2 = document.getElementById("msg-senha2");
	if((senha2.value == "") || (senha.value != senha2.value)){
		erro_senha2.innerHTML = "A senha não confere";
		erro_senha2.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_senha2.style.display = 'none';
	}	

	var concordo = document.getElementById("concordo");
	var erro_concordo = document.getElementById("msg-concordo");
	if(!concordo.checked){
		erro_concordo.innerHTML = "Você precisa concordar com os termos de uso do site";
		erro_concordo.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_concordo.style.display = 'none';
	}		

	if(contErro > 0)
		return false;
	else{
		alert("Cadastro efetuado com sucesso");
	}
}
