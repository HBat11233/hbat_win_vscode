//index.js
//获取应用实例
const app = getApp()
var wxCharts = require('../../utils/wxcharts.js');
var columnChart = null;
var chartData = {
  main: {
    title: '摄入指标',
    data: [898, 1287, 34, 98],
    categories: ['能量', '碳水化合物', '蛋白质', '脂肪']
  }
};
var data0=true;  //输出柱状图单位

Page({
  data: {
    userInfo: {},
    hasUserInfo: false,
    canIUse: wx.canIUse('button.open-type.getUserInfo'),
    headlthNumber: [1,2,3,4,5],
    fristInformation:false,
  },
  //事件处理函数
  bindViewTap: function() {
    wx.navigateTo({
      url: '../logs/logs'
    })
  },
  onLoad: function () {
    if (app.globalData.userInfo) {
      this.setData({
        userInfo: app.globalData.userInfo,
        hasUserInfo: true
      })
    } else if (this.data.canIUse){
      // 由于 getUserInfo 是网络请求，可能会在 Page.onLoad 之后才返回
      // 所以此处加入 callback 以防止这种情况
      app.userInfoReadyCallback = res => {
        this.setData({
          userInfo: res.userInfo,
          hasUserInfo: true
        })
      }
    } else {
      // 在没有 open-type=getUserInfo 版本的兼容处理
      wx.getUserInfo({
        success: res => {
          app.globalData.userInfo = res.userInfo
          this.setData({
            userInfo: res.userInfo,
            hasUserInfo: true
          })
        }
      })
    }
  },
  getUserInfo: function(e) {
    console.log(e)
    app.globalData.userInfo = e.detail.userInfo
    this.setData({
      userInfo: e.detail.userInfo,
      hasUserInfo: true
    })
  },
  submitData: function(event) {
    this.setData({ fristInformation: true })
  },
  onReady: function (e) {
    var windowWidth = 320;
    try {
      var res = wx.getSystemInfoSync();
      windowWidth = res.windowWidth;
    } catch (e) {
      console.error('getSystemInfoSync failed!');
    }

    columnChart = new wxCharts({
      canvasId: 'columnCanvas',
      type: 'column',
      animation: true,  //是否动画显示
      categories: chartData.main.categories,  // (饼图、圆环图不需要) 数据类别分类
      legend:false,
      series: [{
        color: '#f5bda4',
        name: '指标',
        data: chartData.main.data,
        format: function (val, name) {
          var temp = 'g';
          if(data0) {
            temp= 'kj';
            data0=false;
          }
          return val.toFixed(2) + temp;
        }
      }],
      yAxis: {
        disabled :true
      },
      xAxis: {
        disableGrid: false,
        type: 'calibration'
      },
      extra: {
        column: {
          width: 30
        }
      },
      width: windowWidth,
      height: 200
    });
  }
})
