import { useRouter } from 'next/navigation';
const useAuthActions = () => {
    const router = useRouter();

    const PostWithoutAuth = (url:string, body:any) => {

        var request = fetch(`${"http://localhost:8080"}${url}`,  {
            method: "POST", 
            headers: {
            "Content-Type": "application/json",
            },
            body : JSON.stringify(body),
        })

        return request
    }

    const PostWithAuth = async (url: string, body: any) => {

        let response = await PostorPutWithAccessToken(url, "POST", 
            body
        );

        if (response.status === 401) {
            const refreshResponse = await refreshAccessToken();

            if (refreshResponse.ok) {
                const newAccessToken = await refreshResponse.text();
                localStorage.setItem("accessToken", newAccessToken);

                response = await PostorPutWithAccessToken(url, "POST", body);
            } else {
                router.push('/login');
            }
        }
        return response;
    };

    const PutWithAuth = async (url: string, body:any) => {
        let response = await PostorPutWithAccessToken(url, "PUT", 
            body
        );

        if (response.status === 401) {
            const refreshResponse = await refreshAccessToken();

            if (refreshResponse.ok) {
                const newAccessToken = await refreshResponse.text();
                localStorage.setItem("accessToken", newAccessToken);

                response = await PostorPutWithAccessToken(url, "PUT", body);
            } else {
                router.push('/login');
            }
        }
        return response;
    };


    const PostorPutWithAccessToken = (url:string, method:string, body:any) => {
        const accessToken = localStorage.getItem("accessToken");

        const headers: HeadersInit = {
            "Content-Type": "application/json",
        };

        if (accessToken) {
            headers["Authorization"] = accessToken;
        }

        var request = fetch(`${"http://localhost:8080"}${url}`,  {
            method: method, 
            headers: headers,
            body : JSON.stringify(body),
        })
        return request
    }

    const GetWithAuth = async (url: string) => {
        let response = await GetorDeleteWithAccessToken(url, "GET");

        if (response.status === 401) {
            const refreshResponse = await refreshAccessToken();

            if (refreshResponse.ok) {
                const newAccessToken = await refreshResponse.text();
                localStorage.setItem("accessToken", newAccessToken);

                response = await GetorDeleteWithAccessToken(url, "GET");
            } else {
                router.push('/login');
            }
        }
        return response;
    };

    const DeleteWithAuth = async (url: string) => {
        let response = await GetorDeleteWithAccessToken(url, "DELETE");

        if (response.status === 401) {
            const refreshResponse = await refreshAccessToken();

            if (refreshResponse.ok) {
                const newAccessToken = await refreshResponse.text();
                localStorage.setItem("accessToken", newAccessToken);

                response = await GetorDeleteWithAccessToken(url, "DELETE");
            } else {
                router.push('/login');
            }
        }
        return response;
    };

    const GetorDeleteWithAccessToken = (url:string, method:string) => {
        const accessToken = localStorage.getItem("accessToken");

        const headers: HeadersInit = {
            "Content-Type": "application/json",
        };

        if (accessToken) {
            headers["Authorization"] = accessToken;
        }
        
        var request = fetch(`${"http://localhost:8080"}${url}`,  {
            method: method,
            headers: headers
        })

        return request
    }

    const refreshAccessToken = (): Promise<Response> => {
        return fetch("http://localhost:8080/auth/refresh", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({userId: localStorage.getItem("currentUserId"),
                refreshToken: localStorage.getItem("refreshToken")}),
        });
    };

    return { PostWithoutAuth, PostWithAuth, PutWithAuth, GetWithAuth, DeleteWithAuth };
}

export default useAuthActions;