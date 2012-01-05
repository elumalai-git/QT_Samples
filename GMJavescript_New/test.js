var gm = new Object();
//var jsgm = new Object();

gm.jssayHello = function(Success,Failure,data)
{
    var objName = gmint.cppGetObjectName();
    gmint[objName].Success.connect(Success);
    gmint[objName].Failure.connect(Failure);
    gmint[objName].GetAge(data);
/* connecting c++ signal to javescript function */
//    gmint.sigSuccess.connect(jsFunc);
/* This function is calling c++ function */
//    var returnVal = gmint.cppsayHello(data);
/* disconnecting c++ signal to javescript function */
//    gmint.sigSuccess.disconnect(jsFunc);
/* Returning the value to javascript */
//    return returnVal;

}

/*
jsgm.callFunc = function(success,jsFunc,JSON-data)
{
//    jsgm.sigAnother.connect(jsFunc);
    alert("jsgm");
    gmint.sigAnother.connect(jsFunc);
}*/
