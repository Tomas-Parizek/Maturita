function odeslat(email, heslo)
{
    if (email.toLowerCase() === "it@chytrak.cz" &&
    heslo === "SkalkaZdar")
    {
        document.body.removeChild(tabulka);
        alert("Přístup povolen.");
    }
}
