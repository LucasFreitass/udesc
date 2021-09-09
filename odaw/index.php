<?php
session_start();
?>


<!DOCTYPE html>
<html>
    
<head>
    <meta charset="utf-8">
    <title>Lgin para Farmácia</title>

</head>

<body>
        <section class="">
                    <h5 class="">Sistema de Login para farmácia</h5>
                    <?php
                    if(isset($_SESSION['nao_autenticado'])):
                    ?>
                    <div class="">
                      <p>ERRO: Usuário ou senha inválidos.</p>
                    </div>
                    <?php
                    endif;
                    unset($_SESSION['nao_autenticado']);

                    ?>
                    <div class="box">
                        <form action="login.php" method="POST">
                            <div class="field">
                                <div class="control">
                                    <input name="usuario" name="text" class="" placeholder="Seu usuário" autofocus="">
                                </div>
                            </div>

                            <div class="field">
                                <div class="control">
                                    <input name="senha" class="" type="password" placeholder="Sua senha">
                                </div>
                            </div>
                            <button type="submit" class="">Entrar</button>
                        </form>
                    </div>
         </section>
</body>

</html>