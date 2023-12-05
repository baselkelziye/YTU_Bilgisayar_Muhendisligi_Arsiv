import { Component } from '@angular/core';
import { Title } from '@angular/platform-browser';
import Chart, { ChartItem, ChartTypeRegistry } from 'chart.js/auto';
import { ChatbotService } from '../services/chatbot.service';
import { Observable } from 'rxjs';
import { FormControl, Validators } from '@angular/forms';

@Component({
  selector: 'app-chatbot-analytcs',
  templateUrl: './chatbot-analytcs.component.html',
  styleUrls: ['./chatbot-analytcs.component.css']
})
export class ChatbotAnalytcsComponent {
  chartTypeOptions: string[] = ['bar', 'pie', 'line'];
  dataSourceOptions: any[] = [];
  selectedChart!: string;
  analytics$!: Observable<any>;
  selectedDataSource!: string;
  chart!: any;

  dataSourceControl:FormControl = new FormControl('', {validators: [Validators.required]});
  chartSelectControl:FormControl = new FormControl('',{validators: [Validators.required]});

  constructor(private titleService: Title, private chatbotService: ChatbotService){}

  ngOnInit(){
    this.titleService.setTitle("Analytics | TechTalk");

    let obj = {key: 'mostCommonResponse', name: 'Most Common Response'};
    this.dataSourceOptions.push(obj);

    obj = {key: 'leastCommonResponse', name: 'Least Common Response'};
    this.dataSourceOptions.push(obj);

    obj = {key: 'mostCommonPatterns', name: 'Most Common Patterns'};
    this.dataSourceOptions.push(obj);

    obj = {key: 'leastCommonPatterns', name: 'Least Common Patterns'};
    this.dataSourceOptions.push(obj);
  }

  onDataSourceSelectChange(){
    this.onConfigChange();
  }

  onChartSelectChange(){
    this.onConfigChange();
  }

  onConfigChange(){
    const labels: any[] = [];
    const data: any[] = [];

    if(this.dataSourceControl.valid && this.chartSelectControl.valid){
      this.chatbotService.postAnalytics(this.dataSourceControl.value).subscribe((response: any) => {
        console.log(response);
        if(response.res.length > 3){
          response.res.forEach((element:any)=> {
            labels.push(element[0]);
            data.push(element[1]);
            console.log(element);
          });
        }

        else{
          response.res[0].forEach((element:any) => {
            labels.push(element);
          });

          response.res[1].forEach((element: any) => {
            data.push(element)
          })
        }

        this.buildChart(this.chartSelectControl.value, labels,data);
      });
    }
  }

  buildChart(chartType: any, labels: any[], data: any[]){
    const ctx = document.getElementById('myChart') as ChartItem;

    if(this.chart){
      this.chart.destroy();
    }

    if(ctx != null){
      this.chart = new Chart(ctx, {
        type: chartType,
        data: {
          labels: labels,
          datasets: [
            {
            label: '',
            data: data,
            borderWidth: 1
            },
          ]
        },
        options: {
          scales: {
            y: {
              beginAtZero: true
            }
          }
        }
      });
    }
  }
}

