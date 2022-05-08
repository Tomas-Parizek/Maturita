<html>
<head>
    <meta charset="utf-8">
    <title>Kalkulačka</title>

    <style>
        table
        {
            position: absolute;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
        }

        #spocti
        {
            width: 100%;
        }
    </style>
</head>
<body>
<form method="post">
    <table border="1">
        <tr>
            <td>
                <b>První číslo</b>
            </td>
            <td>
                <input type="number" name="a" value="0">
            </td>
        </tr>
        <tr>
            <td>
                <b>Druhé číslo</b>
            </td>
            <td>
                <input type="number" name="b" value="0">
            </td>
        </tr>
        <tr>
            <td>
                <b>Operace</b>
            </td>
            <td>
                <select name="o">
                    <option>+</option>
                    <option>-</option>
                    <option>*</option>
                    <option>/</option>
                    <option>mod</option>
                </select>
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <input type="submit" value="Vypočítat" id="spocti">
            </td>
        </tr>
        <tr>
            <td>
                <b>Výsledek</b>
            </td>
            <td>
                <span id="vysledek"></span>
            </td>
        </tr>
    </table>
</form>

<?php
function zapis($v)
{
    $script = "<script>
    vysledek.innerHTML = $v;
</script>";
    echo $script;
}

if (isset($_POST['a']) &&
isset($_POST['b']) &&
isset($_POST['o']))
{
    $a = $_POST['a'];
    $b = $_POST['b'];
    $o = $_POST['o'];

    if ($o == "+")
        $v = $a + $b;
    else if ($o == "-")
        $v = $a - $b;
    else if ($o == "*")
        $v = $a * $b;
    else if ($o == "/")
        $v = $a / $b;
    else if ($o == "mod")
        $v = $a % $b;

    zapis($v);
}

?>
</body>
</html>
