# DX11 초기화와 IMGUI

### Introduction

강사님께서 소스 코드를 올려주셨다. 320줄짜리 C++ 코드다. 처음부터 하나하나 배워나가는 방법보다는 주어진 코드를 수정하면서 배워가는 방식을 채택한다고 하신다.

**그래픽스의 시작은 컴퓨터로 그림을 그리는 것**이라고 한다. 근본적으로 이는 픽셀에 색을 정해주는 것이다. 따라서 첫 시간에 실습할 것은 색깔과 2차원 좌표 픽셀 다루기이다.

## 색과 2차원 픽셀 실습

```cpp
void Update()
    {
        std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{0.8f, 0.8f, 0.8f, 1.0f});
        pixels[0 + canvasWidth * 0] = Vec4{ 1.0f, 0.0f, 0.0f, 1.0f };
        pixels[1 + canvasWidth * 0] = Vec4{ 1.0f, 1.0f, 0.0f, 1.0f };

        // Update texture buffer
        D3D11_MAPPED_SUBRESOURCE ms;
        deviceContext->Map(canvasTexture, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms);
        memcpy(ms.pData, pixels.data(), pixels.size() * sizeof(Vec4));
        deviceContext->Unmap(canvasTexture, NULL);
    }
```

320줄 코드 중 update 함수 부분이다. 이 함수는 반복 호출되면서 특정 색의 픽셀을 나타내줄 것이다.

우리가 흔히 C++언어를 배우며 아는 컨테이너 vector와 달리, Vec4 구조체는 수학적인 의미의 4차원 벡터를 의미한다. 정확하게는 **Vec4{Red, Blue, Green, 불투명도}**로 구성된다.

### 배경 색 바꿔보기

<img title="" src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/048a2759a23642b85fac58af42a8d5f7ecbe2aad.png" alt="Untitled" data-align="inline" width="315"> <img title="" src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/28d4232bcaf287c3f93813adb98374149debce0c.png" alt="Untitled" width="316">

```cpp
std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{46.0f/255.0f, 139.0f/255.0f, 87.0f/255.0f, 1.0f}); // 배경색 변경
pixels[0 + canvasWidth * 0] = Vec4{ 1.0f, 0.0f, 0.0f, 1.0f };
pixels[1 + canvasWidth * 0] = Vec4{ 1.0f, 1.0f, 0.0f, 1.0f };
...
```

예제 코드의 첫 줄 Vec4의 값을 바꾸니 배경색이 변화하였다. 바꿔준 색은 바다 녹색이며 인터넷에 RGB 색상표를 검색하여 얻은 좌표를 대입하였더니 원하는 색이 나타났다. 밑의 사진이 바로 RGB 색상표의 일부이다.

![Untitled](221113_그래픽스_DX11%20초기화와%20IMGUI_assets/d9ddb375d505d3eeb24f65ad97712ba5ce06cb5f.png)

<RGB 색상표의 일부>

### 픽셀의 좌표와 색 적용하기

배경색과 마찬가지로 두번째 줄부터 나와있는 pixels 또한 Vec4 구조체를 가지므로, 우리는 이것이 빨강색 노랑색 작은 박스를 가리킨다는 것을 눈치챌 수 있다. 따라서 pixels의 좌표에 유의하면서 파란색 박스를 추가하였다.

pixels의 좌표를 보면 (m + Width * n)의 형태로 되어있다. 이는 2차원 좌표를 1차원처럼 사용하기 위한 테크닉이다. 2차원 배열의 좌표가 (i, j)일 때 1차원으로는 (j + i * Width)로 나타낼 수 있다.

<img src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/28d4232bcaf287c3f93813adb98374149debce0c.png" title="" alt="Untitled" width="285"> <img src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/4c15d552a003fdf4677d8869e49a7435d022d98c.png" title="" alt="Untitled" width="285">

```cpp
std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{46.0f/255.0f, 139.0f/255.0f, 87.0f/255.0f, 1.0f});
pixels[0 + canvasWidth * 0] = Vec4{ 1.0f, 0.0f, 0.0f, 1.0f };
pixels[1 + canvasWidth * 0] = Vec4{ 1.0f, 1.0f, 0.0f, 1.0f };
pixels[2 + canvasWidth * 0] = Vec4{ 0.0f, 0.0f, 1.0f, 1.0f }; // 파란색 박스 추가
...
```

### 픽셀이 이동하는 애니메이션 만들기

<img src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/025243c67c1d591494a5ede19255e7016753041b.gif" title="" alt="Animation.gif" width="304"> <img src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/ccb5a1f0740c7d64d93e72addf7b86f64d8e419e.png" title="" alt="Untitled" width="302">

이번에는 정적인 화면이 아니라 왼쪽처럼 픽셀이 이동하는 화면을 만들어볼 것이다. for 반복문을 활용하여 간단하게 구현할 수 있다.

```cpp
static int i = 0;
std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{0.8f, 0.8f, 0.8f, 1.0f});
pixels[i] = Vec4{ 1.0f, 0.0f, 0.0f, 1.0f };
i++;
...
```

그러나 코드를 이렇게 작성하면 오른쪽 화면처럼 마지막 픽셀에 도달하면서 오류가 발생한다. pixels의 범위가 192로 정해져 있기 때문에 i가 192가 되면 오류가 발생하는 것이다. 따라서 if 구문으로 pixel이 마지막에 닿을 때 i를 초기화할 수 있도록 하여 해결하였다.

```cpp
static int i = 0;
std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{0.8f, 0.8f, 0.8f, 1.0f});
pixels[i] = Vec4{ 1.0f, 0.0f, 0.0f, 1.0f };

// if 구문을 통한 i좌표 초기화
if (i >= pixels.size() - 1)
{
    i = 0;
}
else
{
    i++;
}
```

<img src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/15fc0e37706c5f0277833ba4f83c0a4334f909bf.gif" title="" alt="Animation2.gif" width="273">

여기에 코드를 조금 추가하면 위에서 실습한 것과 동일하게 애니메이션에도 색깔을 나타낼 수 있다.

```cpp
static int i = 0;
std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{0.8f, 0.8f, 0.8f, 1.0f});
pixels[i] = i%3 == 0 ? Vec4{ 1.0f, 0.0f, 0.0f, 1.0f }
                        : i%3 == 1 ? Vec4{ 1.0f, 1.0f, 0.0f, 1.0f }
                        : Vec4{ 0.0f, 0.0f, 1.0f, 1.0f };

if (i >= pixels.size() - 1)
{
    i = 0;
}
else
{
    i++;
}
```

밑부분의 나머지 코드를 간단하게 살펴보면 다음과 같은 역할을 한다.

```cpp
void Update()
    {   
        ...
        D3D11_MAPPED_SUBRESOURCE ms;
        deviceContext->Map(canvasTexture, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms); // Map은 GPU와 CPU의 메모리를 대응시킨다.
        memcpy(ms.pData, pixels.data(), pixels.size() * sizeof(Vec4)); // memcpy로 우리가 지정한 pixels의 메모리를 복사한다.
        deviceContext->Unmap(canvasTexture, NULL); // Unmap으로 GPU 메모리를 닫는다.
    }
```

---

### 추가 학습: IMGUI에서 슬라이더로 배경색 바꾸기

<img src="221113_그래픽스_DX11%20초기화와%20IMGUI_assets/eee60529981076dacccc673bc3eaed08547e9ffd.gif" title="" alt="Animation3.gif" width="290">

```cpp
// main.cpp
// ImGui의 slider를 불러온다. slider는 example 파일 내 canvasColor에 영향을 준다.
ImGui::SliderFloat3("RGB(0.0->1.0)", example->canvasColor, 0.0f, 1.0f);

// example.h
// Vec4 내의 색상 좌표를 canvasColor로 지정한다.
std::vector<Vec4> pixels(canvasWidth * canvasHeight, Vec4{canvasColor[0], canvasColor[1], canvasColor[2], 1.0f});
...

// public에 canvasColor를 정의한다.
public:
    float canvasColor[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
```

챕터 1은 Introduction에서도 언급했듯이 DX를 직접 사용하는 것은 아니고, 그래픽스의 원리 이해에 중점을 둔다. 코드를 한줄한줄 설명할 수 있지는 못하지만, 실습을 통해 어떤 객체가 무엇을 나타내고 어떤 원리로 색을 나타내고 변화를 주는지 이해할 수 있는 수업이었다.