<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Přihlášení</title>

    <style>
        #odeslat
        {
            width: 100%;
        }

        #formular
        {
            position: absolute;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
        }
    </style>
</head>
<body>
<form method="post" id="formular">
    <table border="1">
        <tr>
            <td>
                <label for="email">
                    <b>E-mail</b>
                </label>
            </td>
            <td><input type="email" id="email" name="email" value="@"></td>
        </tr>
        <tr>
            <td>
                <label for="heslo">
                    <b>Heslo</b>
                </label>
            </td>
            <td><input type="password" id="heslo" name="heslo"></td>
        </tr>
        <tr>
            <td colspan="2">
                <input type="submit" id="odeslat">
            </td>
        </tr>
    </table>
</form>

<?php

$script = "<script>
    document.body.removeChild(formular);
    alert('Přístup povolen');
</script>";

if (isset($_POST['email']))
{
    $email = $_POST['email'];
    $heslo = $_POST['heslo'];

    if (strtolower($email) == "it@chytrak.cz" &&
        $heslo == "SkalkaZdar")
        echo $script;
}
?>

</body>
</html>


