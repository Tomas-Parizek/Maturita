<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Nastavení barev pozadí</title>

    <style>
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
    <form id="formular" method="post">
        <table border="1">
            <tr>
                <td>
                    <b>
                        Množství červené
                    </b>
                </td>
                <td>
                    <input type="range" name="r" id="r" onchange="formular.submit()" min="0" max="255" value="255">
                </td>
            </tr>
            <tr>
                <td>
                    <b>
                        Množství zelené
                    </b>
                </td>
                <td>
                    <input type="range" name="g" id="g" onchange="formular.submit()" min="0" max="255" value="255">
                </td>
            </tr>
            <tr>
                <td>
                    <b>
                        Množství modré
                    </b>
                </td>
                <td>
                    <input type="range" name="b" id="b" onchange="formular.submit()" min="0" max="255" value="255">
                </td>
            </tr>
        </table>
    </form>

<?php
if (isset($_POST['r']) &&
isset($_POST['g']) &&
isset($_POST['b']))
    {
        $r = $_POST['r'];
        $g = $_POST['g'];
        $b = $_POST['b'];

        $script = "
        <script>
            let barva = 'rgb($r,$g,$b)';
            document.body.style.backgroundColor = barva;
            r.value = $r;
            g.value = $g;
            b.value = $b;
</script>
        ";
        echo $script;
    }
?>
</body>
</html>
