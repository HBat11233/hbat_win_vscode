//diet-records.js
//饮食记录具体页

var app = getApp();
var wxCharts = require('../../utils/wxcharts.js');
var columnCharts = null;
var chartDatas = {
  main: {
    title: '摄入指标',
    data: [0,0,0,0,0,0],
    categories: ['能量', '蛋白质', '脂肪','碳水化合物','不溶性膳食纤维','胆固醇']
  }
};
var data0 = 0;  //输出柱状图单位

Page({
  data:{
    foodlist:[]
  },

  onLoad:function(e) {
    var tp = [];
    for(var i in app.globalData.food1)
    {
      tp.push(false);
    }
    var fl,flb;
    fl = app.globalData.foodlist? app.globalData.foodlist:[];
    flb = app.globalData.foodlistBool? app.globalData.foodlistBool:[];
    this.setData({
      food1: app.globalData.food1,
      food1Index: app.globalData.food1Index,
      foodlistBool:tp,
      foodlist:fl,
      foodlistBool:flb
    })
    this.updataCan();  

  },

  onReady:function(e){
    var windowWidth = 350;
    try {
      var res = wx.getSystemInfoSync();
      windowWidth = res.windowWidth;
    } catch (e) {
      console.error('getSystemInfoSync failed!');
    }
    console.log(windowWidth);
    columnCharts = new wxCharts({
      canvasId: 'canvas',
      type: 'column',
      animation: true,  //是否动画显示
      categories: chartDatas.main.categories,  // (饼图、圆环图不需要) 数据类别分类
      legend: true,
      series: [{
        color: '#f57d73',
        name:'指标',
        data: chartDatas.main.data,
        format: function (val, name) {
          var temp = 'g';
          if (!data0) 
            temp = 'kcal';
          if (data0===5)
            temp='mg';
            data0=data0+1;
          if (data0 === 6)
            data0 = 0;
          return val.toFixed() + temp;
        }
      }],
      yAxis: {
        disabled: false
      },
      xAxis: {
        disableGrid: false,
        type: 'calibration'
      },
      extra: {
        column: {
          width: 30,
          height:30
        }
      },
      width: windowWidth,
      height: 250
    })
  },


  addFoodList: function(e) {
    this.data.addId=e.detail.value;
  },

  onAddId: function(e) {
    if(!this.data.addId)return;
    const Id=this.data.addId;
    const list = this.data.food1;
    this.setData({
      addId:Id
    })
    if(!this.data.foodlistBool[Id-1])
    {
      this.data.foodlist.push(this.data.food1[this.data.addId-1]);
      this.data.foodlistBool[Id-1] = true;
      this.setData({
        foodlist:this.data.foodlist,
        foodlistBool:this.data.foodlistBool
      })
      app.globalData.foodlist=this.data.foodlist;
      app.globalData.foodlistBool=this.data.foodlistBool;
      this.updataCan();  
    }
  },

  updataCan: function(){
    const Id=this.data.addId;
    for(var i in chartDatas.main.categories)
      {
        var t=chartDatas.main.categories[i];
        if(this.data.food1[Id-1][t])
        {
          chartDatas.main.data[i]+=this.data.food1[Id-1][t];
          this.onReady();
        }
      }
  }
})
