function speak(line)
{
    console.log("The "+this.type+" rabbit says '"+line+"'");
}

var whileRabbit = 
{
    type:"while",
    speak:speak
};

var fatRabbit =
{
    type:"fat",
    speak:speak
}

whileRabbit.speak("Oh my ears and whiskers, "+"how late it's getting!");
fatRabbit.speak("I could sure use a carrot right now.");

speak.apply(fatRabbit,["Burp"])
speak.call({type:"fat"},"sdf")

console.log(Object.getPrototypeOf({}) == Object.prototype);//Object.getPrototypeOf(object) //返回object的原型
console.log(Object.getPrototypeOf(Object.prototype));
console.log(Object.getPrototypeOf(console.log) == Function.prototype);
console.log(Object.getPrototypeOf([]) == Array.prototype)
/*
//Object.create(object)  创建以object为原型的对象

var protoRabbot = 
{
    speak:function(line)
    {
        console.log("The " + this.type + " rabbit says '" + line + "'");
    }
};

var killerRabbit = Object.create(protoRabbot);
killerRabbit.type = "killer";
killerRabbit.speak("SKREEEE");
*/

function Rabbit(type)
{
    this.type = type;
};

var killerRabbit = new Rabbit("killer");
var blackRabbit = new Rabbit("black");
console.log(blackRabbit.type);

Rabbit.prototype.speak = function(line)
{
    console.log("The " + this.type + " rabbit says '" + line + "'");
};
blackRabbit.speak("Doom...")

//Object.defineProperty(Object.prototype,"hiddenNonsence",{enumerable:false,value:"hi"});给原型定义不可吗，枚举属性
Object.defineProperty(Object.prototype,"hiddenNonsence",{enumerable:false,value:"hi"});

for(var name in blackRabbit)
{
    console.log(name);
};
console.log(blackRabbit.hiddenNonsence);

// Object.create(null);定义没有原型的对象
var map = Object.create(null);


//多态
function rowHeights(rows)
{
    return rows.map
    (
        function(row)
        {
            return row.reduce
            (
                function(max,cell)
                {
                    return Math.max(max,cell.minHeight());
                }
                ,0
            );
        }
    );
}

function colWideth(rows)
{
    return rows[0].map
    (
        function(_,i)
        {
            return rows.reduce
            (
                function(max,row)
                {
                    return Math.max(max,row[i].minWidth());
                }
                ,0
            );
        }
    );
}

function drawTable(rows)
{
    var heights = rowHeights(rows);
    var widths = colWideth(rows);
    function drawLine(blocks,lineNo)
    {
        return blocks.map
        (
            function(block)
            {
                return block[lineNo];
            }
        ).join(" ");
    }
    function drawRow(row,rowNum)
    {
        var blocks = row.map
        (
            function(cell,colNum)
            {
                return cell.draw(widths[colNum],heights[rowNum]);
            }
        );
        return blocks[0].map
        (
            function(_,lineNo)
            {
                return drawLine(blocks,lineNo);
            }
        ).join("\n");
    }
    return rows.map(drawRow).join("\n");
}

function repeat(string,times)
{
    var result = " ";
    for(var i = 0;i<times;i++)
        result += string;
    return result;
}

function TextCell(text)
{
    this.text = text.split("\n");
}

TextCell.prototype.minWidth = function()
{
    return this.text.reduce
    (
        function(width,line)
        {
            return Math.max(width,line.length);
        }
        ,0
    );
};

TextCell.prototype.minHeight = function()
{
    return this.text.length;
};

TextCell.prototype.draw = function(width,height)
{
    var result = [];
    for(var i = 0;i < height; i++)
    {
        var line = this.text[i] || "";
        result.push(line + repeat(" ",width - line.length));
    }
    return result;
};

var rows = [];
for(var i=0;i<5;i++)
{
    var row = [];
    for(var j = 0 ;j<5;++j)
    {
        if((j+i)%2==0)
            row.push(new TextCell("##"));
        else 
            row.push(new TextCell("  "));
    }
    rows.push(row);
}
console.log(drawTable(rows));