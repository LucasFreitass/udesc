<?php
session_start();
?>  

<!doctype html>
<html>
<h4>Olá Sr. <?php echo $_SESSION['usuario'];?></h4>

    <head>
    <link rel="stylesheet" type="text/css" href="estilo.css" media="screen">

        <title>Cadastro pacientes</title>
    </head>

    <body>  
        <div>
            <h3 id="titulo">Cadastramento de pacientes</h3>
            <br>
        </div>

        <form method="post" action="proc_cadastro_farmacia.php" id="formulario" onSubmit="return validacaoFormu();">


            <fieldset class="grupo">
                <div class="campo">
                    <label for="nome_pac"><strong>Nome do paciente</strong></label>
                    <input type="text" name="nome_pac" id="nome_pac" >
                </div>


            </fieldset> 

            <div class="campo">
                <label for="email"><strong>Email do paciente</strong></label>
                <input type="email" name="email" id="email" >
            </div>

          
            <div class="campo">
                <label><strong>Qual o gênero do paciente?</strong></label>
                <label>
                    <input type="radio" name="genero" value="homem" checked>Homem
                </label>
                <label>
                    <input type="radio" name="genero" value="mulher">Mulher
                </label>
                <label>
                    <input type="radio" name="genero" value="outros">Outros
                </label>
            </div>

            <div class="campo">
                    <label for="nome_reme"><strong>Nome do remédio</strong></label>
                    <input type="text" name="nome_reme" id="nome_reme" >
                </div>
           
           
            <div class="campo">
                <label for="tarja"><strong>Selecione a tarja do remédio:</strong></label>
                <select id="tarja" name="tarja" >
                  <option selected disabled value="tarja">Selecione</option>
                  <option value="amarelo">Tarja amarela </option>
                  <option value="vermelha com receita">Tarja vermelha (sem receita)</option>
                  <option value="vermelha sem receita">Tarja vermelha (com receita)</option>
                  <option value="preto">Tarja preta</option>
                </select>
            </div>

            <div class="campo">
                <br>
                <label for="extras"><strong>Caixa de texto aberta para informações extras: </strong></label>
                <textarea rows="6" style="width: 26em" id="extras" name="extras"></textarea>
            </div>

    
                </div>
            </fieldset>

            <button class="botao" type="submit" id="botao" onsubmit="">Concluído</button>      
            <button class = "botao2" type="reset" onreset="">Resetar dados</button>

        </form>

    </body>

    <script>
  function validacaoFormu() {
    var tarja = document.getElementById("tarja").value;
    if (tarja !== "") {
      return true;    
    } else
    alert("Campo de seleção está vazio, selecione uma opção!!");
    return false;
  }
</script>

<html>
<h5><a href="painel.php">Voltar para o painel</a></h5>
</html>

</html>